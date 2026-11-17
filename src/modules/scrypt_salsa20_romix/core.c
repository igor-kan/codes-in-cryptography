#include "interface.h"
#include <string.h>

static uint32_t r32(uint32_t a, int b) { return (a << b) | (a >> (32 - b)); }

void scrypt_salsa20_8(uint32_t B[16]) {
    uint32_t x[16];
    memcpy(x, B, sizeof(x));
    for (int i = 0; i < 4; ++i) {
        x[ 4] ^= r32(x[ 0] + x[12],  7); x[ 8] ^= r32(x[ 4] + x[ 0],  9);
        x[12] ^= r32(x[ 8] + x[ 4], 13); x[ 0] ^= r32(x[12] + x[ 8], 18);
        x[ 9] ^= r32(x[ 5] + x[ 1],  7); x[13] ^= r32(x[ 9] + x[ 5],  9);
        x[ 1] ^= r32(x[13] + x[ 9], 13); x[ 5] ^= r32(x[ 1] + x[13], 18);
        x[14] ^= r32(x[10] + x[ 6],  7); x[ 2] ^= r32(x[14] + x[10],  9);
        x[ 6] ^= r32(x[ 2] + x[14], 13); x[10] ^= r32(x[ 6] + x[ 2], 18);
        x[ 3] ^= r32(x[15] + x[11],  7); x[ 7] ^= r32(x[ 3] + x[15],  9);
        x[11] ^= r32(x[ 7] + x[ 3], 13); x[15] ^= r32(x[11] + x[ 7], 18);

        x[ 1] ^= r32(x[ 0] + x[ 3],  7); x[ 2] ^= r32(x[ 1] + x[ 0],  9);
        x[ 3] ^= r32(x[ 2] + x[ 1], 13); x[ 0] ^= r32(x[ 3] + x[ 2], 18);
        x[ 6] ^= r32(x[ 5] + x[ 4],  7); x[ 7] ^= r32(x[ 6] + x[ 5],  9);
        x[ 4] ^= r32(x[ 7] + x[ 6], 13); x[ 5] ^= r32(x[ 4] + x[ 7], 18);
        x[11] ^= r32(x[10] + x[ 9],  7); x[ 8] ^= r32(x[11] + x[10],  9);
        x[ 9] ^= r32(x[ 8] + x[11], 13); x[10] ^= r32(x[ 9] + x[ 8], 18);
        x[12] ^= r32(x[15] + x[14],  7); x[13] ^= r32(x[12] + x[15],  9);
        x[14] ^= r32(x[13] + x[12], 13); x[15] ^= r32(x[14] + x[13], 18);
    }
    for (int i = 0; i < 16; ++i) B[i] += x[i];
}

void scrypt_blockmix(const uint32_t* B, uint32_t* Y, size_t r) {
    uint32_t X[16];
    size_t words = 32 * r;
    memcpy(X, B + words - 16, 64);
    for (size_t i = 0; i < 2 * r; ++i) {
        scrypt_fast_xor32(X, X, B + i * 16, 16);
        scrypt_salsa20_8(X);
        size_t dst_block = (i & 1) ? (r + i / 2) : (i / 2);
        memcpy(Y + dst_block * 16, X, 64);
    }
}

scrypt_salsa20_romix_err_t scrypt_romix(uint32_t* B, size_t r, size_t N, uint32_t* V) {
    scrypt_salsa20_romix_err_t err = scrypt_validate_n(N, r);
    if (err != SCRYPT_SALSA20_ROMIX_OK || !B || !V) return SCRYPT_SALSA20_ROMIX_ERR_INVALID;
    size_t words = 32 * r;
    uint32_t Y[512];
    if (words > 512) return SCRYPT_SALSA20_ROMIX_ERR_BOUNDS;
    for (size_t i = 0; i < N; ++i) {
        memcpy(V + i * words, B, words * sizeof(uint32_t));
        scrypt_blockmix(B, Y, r);
        memcpy(B, Y, words * sizeof(uint32_t));
    }
    for (size_t i = 0; i < N; ++i) {
        uint32_t j = (uint32_t)(B[words - 16] & (N - 1));
        scrypt_fast_xor32(B, B, V + (size_t)j * words, words);
        scrypt_blockmix(B, Y, r);
        memcpy(B, Y, words * sizeof(uint32_t));
    }
    return SCRYPT_SALSA20_ROMIX_OK;
}
