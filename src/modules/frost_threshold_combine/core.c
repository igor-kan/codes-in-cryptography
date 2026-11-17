#include "interface.h"

uint64_t mod_add_q(uint64_t a, uint64_t b) { return ((a % FROST_Q) + (b % FROST_Q)) % FROST_Q; }
uint64_t mod_mul_q(uint64_t a, uint64_t b) { return (uint64_t)(((__uint128_t)a * b) % FROST_Q); }

static uint64_t pow_mod_q(uint64_t base, uint64_t exp) {
    uint64_t res = 1; base %= FROST_Q;
    while (exp > 0) {
        if (exp & 1ULL) res = mod_mul_q(res, base);
        base = mod_mul_q(base, base);
        exp >>= 1;
    }
    return res;
}

uint64_t mod_inv_q(uint64_t a) { return pow_mod_q(a, FROST_Q - 2); }

uint64_t pow_mod_p(uint64_t base, uint64_t exp) {
    uint64_t res = 1; base %= FROST_P;
    while (exp > 0) {
        if (exp & 1ULL) res = (uint64_t)(((__uint128_t)res * base) % FROST_P);
        base = (uint64_t)(((__uint128_t)base * base) % FROST_P);
        exp >>= 1;
    }
    return res;
}

frost_threshold_combine_err_t frost_lagrange_coeff(const uint64_t* ids, size_t t, size_t idx, uint64_t* out_lam) {
    if (!ids || !out_lam) return FROST_THRESHOLD_COMBINE_ERR_NULL;
    uint64_t num = 1, den = 1;
    uint64_t xi = ids[idx] % FROST_Q;
    for (size_t j = 0; j < t; ++j) {
        if (j == idx) continue;
        uint64_t xj = ids[j] % FROST_Q;
        num = mod_mul_q(num, xj);
        uint64_t diff = (xj >= xi) ? (xj - xi) : (FROST_Q - (xi - xj));
        if (diff == 0) return FROST_THRESHOLD_COMBINE_ERR_INVALID;
        den = mod_mul_q(den, diff);
    }
    *out_lam = mod_mul_q(num, mod_inv_q(den));
    return FROST_THRESHOLD_COMBINE_OK;
}

uint64_t frost_combine_partial_sigs(const uint64_t* ids, const uint64_t* z_parts, size_t t) {
    (void)ids;
    uint64_t sum = 0;
    for (size_t i = 0; i < t; ++i) sum = mod_add_q(sum, z_parts[i]);
    return sum;
}

bool frost_verify_schnorr(uint64_t pk, uint64_t R, uint64_t c, uint64_t z) {
    uint64_t lhs = pow_mod_p(FROST_G, z);
    uint64_t rhs = (uint64_t)(((__uint128_t)R * pow_mod_p(pk, c)) % FROST_P);
    return lhs == rhs;
}
