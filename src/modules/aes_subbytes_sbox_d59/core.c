#include "interface.h"
#include <math.h>
#include <string.h>

static uint8_t gf256_m(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    for (int i = 0; i < 8; ++i) {
        if (b & 1u) p ^= a;
        uint8_t hi = a & 0x80u; a <<= 1; if (hi) a ^= 0x1Bu; b >>= 1;
    }
    return p;
}

static uint8_t gf256_i(uint8_t a) {
    if (a == 0) return 0;
    uint8_t r = 1, b = a, e = 254;
    for (int i = 0; i < 8; ++i) { if (e & 1u) r = gf256_m(r, b); b = gf256_m(b, b); e >>= 1; }
    return r;
}

static uint8_t rotl8(uint8_t x, int s) { return (uint8_t)((x << s) | (x >> (8 - s))); }

uint8_t aes_sbox_alg(uint8_t x) {
    uint8_t v = gf256_i(x);
    return (uint8_t)(v ^ rotl8(v, 1) ^ rotl8(v, 2) ^ rotl8(v, 3) ^ rotl8(v, 4) ^ 0x63u);
}

uint8_t aes_inv_sbox_alg(uint8_t y) {
    uint8_t b = (uint8_t)(rotl8(y, 1) ^ rotl8(y, 3) ^ rotl8(y, 6) ^ 0x05u);
    return gf256_i(b);
}
