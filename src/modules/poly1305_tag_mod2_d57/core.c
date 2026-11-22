#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t mod_m61(__uint128_t v) {
    const uint64_t M61 = (1ULL << 61) - 1ULL;
    uint64_t res = (uint64_t)(v >> 61) + ((uint64_t)v & M61);
    if (res >= M61) res -= M61;
    res = (res >> 61) + (res & M61);
    if (res >= M61) res -= M61;
    return res;
}

uint64_t cw61_mac(uint64_t r, uint64_t s, const uint64_t *blocks, size_t n) {
    const uint64_t M61 = (1ULL << 61) - 1ULL;
    uint64_t rk = r & ((1ULL << 60) - 1ULL);
    uint64_t acc = 0;
    for (size_t i = 0; i < n; ++i) {
        uint64_t m = blocks[i] % M61;
        acc = mod_m61((__uint128_t)(acc + m) * rk);
    }
    return (acc + s) % M61;
}
