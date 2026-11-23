#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t perm64_mac(uint64_t x, uint64_t k) {
    x = (x ^ k) * 0x9E3779B97F4A7C15ULL;
    x ^= x >> 27;
    x *= 0xBF58476D1CE4E5B9ULL;
    return x ^ (x >> 31);
}

uint64_t cbc_mac64(uint64_t key, const uint64_t *blocks, size_t n) {
    uint64_t state = perm64_mac((uint64_t)n, key);
    for (size_t i = 0; i < n; ++i) {
        state = perm64_mac(state ^ blocks[i], key);
    }
    return state;
}
