#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t f_round(uint32_t r, uint32_t k) {
    uint32_t v = (r ^ k) * 0x9E3779B1u;
    v ^= v >> 16;
    return (v << 7) | (v >> 25);
}

uint64_t feistel4_enc(uint64_t x, const uint32_t rk[4]) {
    uint32_t l = (uint32_t)(x >> 32);
    uint32_t r = (uint32_t)(x & 0xFFFFFFFFu);
    for (int i = 0; i < 4; ++i) {
        uint32_t nl = r;
        uint32_t nr = l ^ f_round(r, rk[i]);
        l = nl;
        r = nr;
    }
    return ((uint64_t)l << 32) | (uint64_t)r;
}

uint64_t feistel4_dec(uint64_t x, const uint32_t rk[4]) {
    uint32_t l = (uint32_t)(x >> 32);
    uint32_t r = (uint32_t)(x & 0xFFFFFFFFu);
    for (int i = 3; i >= 0; --i) {
        uint32_t pr = l;
        uint32_t pl = r ^ f_round(pr, rk[i]);
        l = pl;
        r = pr;
    }
    return ((uint64_t)l << 32) | (uint64_t)r;
}
