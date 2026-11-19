#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t b_pow(uint64_t base, uint64_t exp) {
    uint64_t r = 1; base %= BLAK_P;
    while (exp > 0) {
        if (exp & 1ULL) r = (uint64_t)(((__uint128_t)r * base) % BLAK_P);
        base = (uint64_t)(((__uint128_t)base * base) % BLAK_P);
        exp >>= 1;
    }
    return r;
}
hyperplane_share_t blak_deal_share(uint64_t s, uint64_t y0, uint64_t a, uint64_t b) {
    uint64_t c = (uint64_t)(((__uint128_t)a * s + (__uint128_t)b * y0) % BLAK_P);
    return (hyperplane_share_t){a % BLAK_P, b % BLAK_P, c};
}
uint64_t blak_recover_secret(hyperplane_share_t s1, hyperplane_share_t s2) {
    uint64_t d1 = (uint64_t)(((__uint128_t)s1.a * s2.b) % BLAK_P);
    uint64_t d2 = (uint64_t)(((__uint128_t)s2.a * s1.b) % BLAK_P);
    uint64_t det = (d1 + BLAK_P - d2) % BLAK_P;
    uint64_t n1 = (uint64_t)(((__uint128_t)s1.c * s2.b) % BLAK_P);
    uint64_t n2 = (uint64_t)(((__uint128_t)s2.c * s1.b) % BLAK_P);
    uint64_t num = (n1 + BLAK_P - n2) % BLAK_P;
    return (uint64_t)(((__uint128_t)num * b_pow(det, BLAK_P - 2)) % BLAK_P);
}
