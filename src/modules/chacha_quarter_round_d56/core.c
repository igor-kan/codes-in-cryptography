#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rotl32_cc(uint32_t v, int k) {
    return (v << k) | (v >> (32 - k));
}

void chacha_qr(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d) {
    *a += *b; *d ^= *a; *d = rotl32_cc(*d, 16);
    *c += *d; *b ^= *c; *b = rotl32_cc(*b, 12);
    *a += *b; *d ^= *a; *d = rotl32_cc(*d, 8);
    *c += *d; *b ^= *c; *b = rotl32_cc(*b, 7);
}

void chacha20_block_words(const uint32_t in[16], uint32_t out[16]) {
    uint32_t x[16];
    for (int i = 0; i < 16; ++i) x[i] = in[i];
    for (int i = 0; i < 10; ++i) {
        chacha_qr(&x[0], &x[4], &x[8],  &x[12]);
        chacha_qr(&x[1], &x[5], &x[9],  &x[13]);
        chacha_qr(&x[2], &x[6], &x[10], &x[14]);
        chacha_qr(&x[3], &x[7], &x[11], &x[15]);
        chacha_qr(&x[0], &x[5], &x[10], &x[15]);
        chacha_qr(&x[1], &x[6], &x[11], &x[12]);
        chacha_qr(&x[2], &x[7], &x[8],  &x[13]);
        chacha_qr(&x[3], &x[4], &x[9],  &x[14]);
    }
    for (int i = 0; i < 16; ++i) out[i] = x[i] + in[i];
}
