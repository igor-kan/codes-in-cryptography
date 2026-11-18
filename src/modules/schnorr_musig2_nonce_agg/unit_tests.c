#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(schnorr_musig2_nonce_agg_validate_len(1) == SCHNORR_MUSIG2_NONCE_AGG_OK);
    musig_nonce_t ns[2] = {
        {11, 23, musig_pow_p(MUSIG_G, 11), musig_pow_p(MUSIG_G, 23)},
        {17, 31, musig_pow_p(MUSIG_G, 17), musig_pow_p(MUSIG_G, 31)}
    };
    uint64_t b = musig_bind_coeff(ns, 2, 999ULL);
    uint64_t R = musig_agg_pub_nonce(ns, 2, b);
    uint64_t k_tot = ((11 + 17) + (uint64_t)(((__uint128_t)(23 + 31) * b) % MUSIG_Q)) % MUSIG_Q;
    assert(R == musig_pow_p(MUSIG_G, k_tot));
    assert(schnorr_musig2_nonce_agg_verify_guard(true) == SCHNORR_MUSIG2_NONCE_AGG_OK);
    return 0;
}
