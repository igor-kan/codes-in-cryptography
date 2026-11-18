#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t load_le64(const uint8_t* p) {
    uint64_t v = 0;
    for (int i = 0; i < 8; ++i) v |= ((uint64_t)p[i]) << (8 * i);
    return v;
}
void poly1305_clamp_key(const uint8_t raw[32], poly1305_key_t* out) {
    uint8_t c[16];
    memcpy(c, raw, 16);
    c[3] &= 15; c[7] &= 15; c[11] &= 15; c[15] &= 15;
    c[4] &= 252; c[8] &= 252; c[12] &= 252;
    out->r_lo = load_le64(c);
    out->r_hi = load_le64(c + 8);
    out->s_lo = load_le64(raw + 16);
    out->s_hi = load_le64(raw + 24);
}
uint64_t poly1305_short_tag64(const poly1305_key_t* k, const uint64_t* blocks, size_t n) {
    const __uint128_t P = (((__uint128_t)1 << 64) - 59);
    __uint128_t acc = 0;
    __uint128_t r = k->r_lo % P;
    for (size_t i = 0; i < n; ++i) {
        acc = ((acc + blocks[i]) * r) % P;
    }
    return (uint64_t)((acc + k->s_lo) & 0xffffffffffffffffULL);
}
