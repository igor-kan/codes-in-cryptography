#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t round_fn8(uint32_t r, uint32_t k) {
    uint32_t v = (r + k) * 0x85EBCA6Bu;
    return ((v << 11) | (v >> 21)) ^ (v >> 13);
}

uint64_t feistel8_enc(uint64_t pt, const uint32_t rk[8]) {
    uint32_t l = (uint32_t)(pt >> 32), r = (uint32_t)(pt & 0xFFFFFFFFu);
    for (int i = 0; i < 8; ++i) {
        uint32_t nr = l ^ round_fn8(r, rk[i]);
        l = r; r = nr;
    }
    return ((uint64_t)l << 32) | (uint64_t)r;
}

uint64_t feistel8_dec(uint64_t ct, const uint32_t rk[8]) {
    uint32_t l = (uint32_t)(ct >> 32), r = (uint32_t)(ct & 0xFFFFFFFFu);
    for (int i = 7; i >= 0; --i) {
        uint32_t pr = l;
        uint32_t pl = r ^ round_fn8(pr, rk[i]);
        l = pl; r = pr;
    }
    return ((uint64_t)l << 32) | (uint64_t)r;
}
