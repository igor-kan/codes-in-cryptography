#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t pedersen_pow_d60(uint64_t base, uint64_t exp) {
    uint64_t res = 1ULL;
    base %= PED_P;
    while (exp > 0) {
        if (exp & 1ULL) res = (uint64_t)(((__uint128_t)res * base) % PED_P);
        base = (uint64_t)(((__uint128_t)base * base) % PED_P);
        exp >>= 1;
    }
    return res;
}
uint64_t pedersen_commit_d60(uint64_t v, uint64_t r) {
    uint64_t gv = pedersen_pow_d60(PED_G, v % PED_Q);
    uint64_t hr = pedersen_pow_d60(PED_H, r % PED_Q);
    return (uint64_t)(((__uint128_t)gv * hr) % PED_P);
}
bool pedersen_verify_d60(uint64_t c, uint64_t v, uint64_t r) {
    return c == pedersen_commit_d60(v, r);
}
