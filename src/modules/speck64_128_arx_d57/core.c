#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t ror32_sp(uint32_t x, int r) { return (x >> r) | (x << (32 - r)); }
static uint32_t rol32_sp(uint32_t x, int r) { return (x << r) | (x >> (32 - r)); }

void speck64_expand(const uint32_t k[4], uint32_t rk[27]) {
    uint32_t b = k[0], l[3] = {k[1], k[2], k[3]};
    rk[0] = b;
    for (uint32_t i = 0; i < 26; ++i) {
        uint32_t li = l[i % 3];
        li = (ror32_sp(li, 8) + b) ^ i;
        b = rol32_sp(b, 3) ^ li;
        l[i % 3] = li;
        rk[i + 1] = b;
    }
}

void speck64_enc(uint32_t v[2], const uint32_t rk[27]) {
    uint32_t y = v[0], x = v[1];
    for (int i = 0; i < 27; ++i) {
        x = (ror32_sp(x, 8) + y) ^ rk[i];
        y = rol32_sp(y, 3) ^ x;
    }
    v[0] = y; v[1] = x;
}

void speck64_dec(uint32_t v[2], const uint32_t rk[27]) {
    uint32_t y = v[0], x = v[1];
    for (int i = 26; i >= 0; --i) {
        y = ror32_sp(y ^ x, 3);
        x = rol32_sp((x ^ rk[i]) - y, 8);
    }
    v[0] = y; v[1] = x;
}
