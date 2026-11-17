#include "interface.h"

frost_threshold_combine_err_t verify_threshold_roundtrip(void) {
    uint64_t key_poly[3] = {1234567ULL, 998877ULL, 554433ULL};
    uint64_t k_poly[3]   = {7654321ULL, 112233ULL, 445566ULL};
    uint64_t all_ids[5] = {1, 2, 3, 4, 5};
    uint64_t sk[5], nk[5];
    frost_parallel_eval_shares(key_poly, 2, all_ids, sk, 5);
    frost_parallel_eval_shares(k_poly, 2, all_ids, nk, 5);
    uint64_t ids_sub[3] = {1, 3, 5};
    uint64_t z_parts[3];
    uint64_t c = 424242ULL;
    for (int i = 0; i < 3; ++i) {
        size_t pos = (size_t)(ids_sub[i] - 1);
        uint64_t lam = 0;
        if (frost_lagrange_coeff(ids_sub, 3, (size_t)i, &lam) != FROST_THRESHOLD_COMBINE_OK) return FROST_THRESHOLD_COMBINE_ERR_INVALID;
        uint64_t scaled_sk = mod_mul_q(lam, sk[pos]);
        uint64_t scaled_k  = mod_mul_q(lam, nk[pos]);
        z_parts[i] = mod_add_q(scaled_k, mod_mul_q(scaled_sk, c));
    }
    uint64_t z = frost_combine_partial_sigs(ids_sub, z_parts, 3);
    uint64_t pk = pow_mod_p(FROST_G, key_poly[0]);
    uint64_t R  = pow_mod_p(FROST_G, k_poly[0]);
    return frost_verify_schnorr(pk, R, c, z) ? FROST_THRESHOLD_COMBINE_OK : FROST_THRESHOLD_COMBINE_ERR_INVARIANT;
}
