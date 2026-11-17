#include "interface.h"

static uint64_t rol64(uint64_t x, int r) { return (x << r) | (x >> (64 - r)); }
static uint64_t ror64(uint64_t x, int r) { return (x >> r) | (x << (64 - r)); }

void fast_speck128_pair(kek128_t kek, uint64_t* a, uint64_t* b, bool invert) {
    uint64_t rk[32];
    uint64_t k = kek.k0, l = kek.k1;
    for (uint64_t r = 0; r < 32; ++r) {
        rk[r] = k;
        l = (ror64(l, 8) + k) ^ r;
        k = rol64(k, 3) ^ l;
    }
    uint64_t x = *a, y = *b;
    if (!invert) {
        for (int r = 0; r < 32; ++r) {
            x = (ror64(x, 8) + y) ^ rk[r];
            y = rol64(y, 3) ^ x;
        }
    } else {
        for (int r = 31; r >= 0; --r) {
            y = ror64(y ^ x, 3);
            x = rol64((x ^ rk[r]) - y, 8);
        }
    }
    *a = x;
    *b = y;
}
