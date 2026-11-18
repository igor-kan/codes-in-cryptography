#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t musig_pow_p(uint64_t base, uint64_t exp) {
    uint64_t res = 1; base %= MUSIG_P;
    while (exp > 0) {
        if (exp & 1ULL) res = (uint64_t)(((__uint128_t)res * base) % MUSIG_P);
        base = (uint64_t)(((__uint128_t)base * base) % MUSIG_P);
        exp >>= 1;
    }
    return res;
}
uint64_t musig_bind_coeff(const musig_nonce_t* nonces, size_t n, uint64_t msg) {
    uint64_t h = msg ^ 0x9e3779b97f4a7c15ULL;
    for (size_t i = 0; i < n; ++i) {
        h = (h ^ nonces[i].R1) * 0xbf58476d1ce4e5b9ULL;
        h = (h ^ nonces[i].R2) * 0x94d049bb133111ebULL;
    }
    return (h % (MUSIG_Q - 1)) + 1;
}
uint64_t musig_agg_pub_nonce(const musig_nonce_t* nonces, size_t n, uint64_t b) {
    uint64_t prod1 = 1, prod2 = 1;
    for (size_t i = 0; i < n; ++i) {
        prod1 = (uint64_t)(((__uint128_t)prod1 * nonces[i].R1) % MUSIG_P);
        prod2 = (uint64_t)(((__uint128_t)prod2 * nonces[i].R2) % MUSIG_P);
    }
    uint64_t p2b = musig_pow_p(prod2, b);
    return (uint64_t)(((__uint128_t)prod1 * p2b) % MUSIG_P);
}
