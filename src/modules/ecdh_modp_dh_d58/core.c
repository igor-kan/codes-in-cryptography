#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t dh_pow_mod(uint64_t g, uint64_t exp, uint64_t p) {
    uint64_t res = 1ULL;
    uint64_t base = g % p;
    while (exp > 0) {
        if (exp & 1ULL) res = (uint64_t)(((__uint128_t)res * base) % p);
        base = (uint64_t)(((__uint128_t)base * base) % p);
        exp >>= 1;
    }
    return res;
}
