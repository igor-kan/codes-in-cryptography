#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t mulmod64(uint64_t a, uint64_t b, uint64_t m) {
    return (uint64_t)(((__uint128_t)a * b) % m);
}

uint64_t mont_ladder_modexp(uint64_t base, uint64_t exp, uint64_t mod) {
    if (mod <= 1) return 0;
    uint64_t r0 = 1ULL;
    uint64_t r1 = base % mod;
    for (int i = 63; i >= 0; --i) {
        uint64_t bit = (exp >> i) & 1ULL;
        uint64_t mask = 0ULL - bit;
        uint64_t t_mul = mulmod64(r0, r1, mod);
        uint64_t s0 = mulmod64(r0, r0, mod);
        uint64_t s1 = mulmod64(r1, r1, mod);
        r0 = (t_mul & mask) | (s0 & ~mask);
        r1 = (s1 & mask) | (t_mul & ~mask);
    }
    return r0;
}
