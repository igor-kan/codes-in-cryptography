#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rol32_sm(uint32_t x, int r) { return (x << r) | (x >> (32 - r)); }
static uint32_t f_simon(uint32_t x) { return (rol32_sm(x, 1) & rol32_sm(x, 8)) ^ rol32_sm(x, 2); }

void simon64_expand(const uint32_t k[4], uint32_t rk[44]) {
    const uint64_t z3 = 0x7369f885192c0ef5ULL;
    for (int i = 0; i < 4; ++i) rk[i] = k[i];
    for (int i = 4; i < 44; ++i) {
        uint32_t tmp = ((rk[i - 1] >> 3) | (rk[i - 1] << 29)) ^ rk[i - 3];
        tmp ^= ((tmp >> 1) | (tmp << 31));
        uint32_t zbit = (uint32_t)((z3 >> ((i - 4) % 62)) & 1ULL);
        rk[i] = (~rk[i - 4]) ^ tmp ^ zbit ^ 3u;
    }
}

void simon64_enc(uint32_t v[2], const uint32_t rk[44]) {
    uint32_t y = v[0], x = v[1];
    for (int i = 0; i < 44; ++i) {
        uint32_t tmp = x;
        x = y ^ f_simon(x) ^ rk[i];
        y = tmp;
    }
    v[0] = y; v[1] = x;
}

void simon64_dec(uint32_t v[2], const uint32_t rk[44]) {
    uint32_t y = v[0], x = v[1];
    for (int i = 43; i >= 0; --i) {
        uint32_t tmp = y;
        y = x ^ f_simon(y) ^ rk[i];
        x = tmp;
    }
    v[0] = y; v[1] = x;
}
