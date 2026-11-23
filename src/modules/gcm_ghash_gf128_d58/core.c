#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t gf64_mul(uint64_t a, uint64_t b) {
    uint64_t z = 0ULL;
    for (int i = 0; i < 64; ++i) {
        if ((b >> i) & 1ULL) z ^= a;
        uint64_t hi = a >> 63;
        a <<= 1;
        if (hi) a ^= 0x1BULL;
    }
    return z;
}

uint64_t ghash64_blocks(uint64_t h, const uint64_t *blocks, size_t n) {
    uint64_t y = 0ULL;
    for (size_t i = 0; i < n; ++i) {
        y = gf64_mul(y ^ blocks[i], h);
    }
    return y;
}
