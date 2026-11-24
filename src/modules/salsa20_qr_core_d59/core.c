#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rotl32_sa(uint32_t a, int b) { return (a << b) | (a >> (32 - b)); }

void salsa_qr(uint32_t *y0, uint32_t *y1, uint32_t *y2, uint32_t *y3) {
    *y1 ^= rotl32_sa(*y0 + *y3, 7);
    *y2 ^= rotl32_sa(*y1 + *y0, 9);
    *y3 ^= rotl32_sa(*y2 + *y1, 13);
    *y0 ^= rotl32_sa(*y3 + *y2, 18);
}

void salsa20_core(const uint32_t in[16], uint32_t out[16]) {
    uint32_t x[16];
    for (int i = 0; i < 16; ++i) x[i] = in[i];
    for (int i = 0; i < 10; ++i) {
        salsa_qr(&x[0], &x[4], &x[8],  &x[12]);
        salsa_qr(&x[5], &x[9], &x[13], &x[1]);
        salsa_qr(&x[10],&x[14],&x[2],  &x[6]);
        salsa_qr(&x[15],&x[3], &x[7],  &x[11]);
        salsa_qr(&x[0], &x[1], &x[2],  &x[3]);
        salsa_qr(&x[5], &x[6], &x[7],  &x[4]);
        salsa_qr(&x[10],&x[11],&x[8],  &x[9]);
        salsa_qr(&x[15],&x[12],&x[13], &x[14]);
    }
    for (int i = 0; i < 16; ++i) out[i] = x[i] + in[i];
}
