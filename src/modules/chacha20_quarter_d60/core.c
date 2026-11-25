#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rotl32(uint32_t v, int n) { return (v << n) | (v >> (32 - n)); }
void chacha20_qround_d60(uint32_t* x, int a, int b, int c, int d) {
    x[a] += x[b]; x[d] ^= x[a]; x[d] = rotl32(x[d], 16);
    x[c] += x[d]; x[b] ^= x[c]; x[b] = rotl32(x[b], 12);
    x[a] += x[b]; x[d] ^= x[a]; x[d] = rotl32(x[d], 8);
    x[c] += x[d]; x[b] ^= x[c]; x[b] = rotl32(x[b], 7);
}
void chacha20_block_words_d60(const uint32_t key[8], uint32_t ctr, const uint32_t nonce[3], uint32_t out[16]) {
    uint32_t init[16] = {
        0x61707865U, 0x3320646eU, 0x79622d32U, 0x6b206574U,
        key[0], key[1], key[2], key[3], key[4], key[5], key[6], key[7],
        ctr, nonce[0], nonce[1], nonce[2]
    };
    uint32_t x[16];
    memcpy(x, init, sizeof(x));
    for (int r = 0; r < 10; ++r) {
        chacha20_qround_d60(x, 0, 4, 8, 12);
        chacha20_qround_d60(x, 1, 5, 9, 13);
        chacha20_qround_d60(x, 2, 6, 10, 14);
        chacha20_qround_d60(x, 3, 7, 11, 15);
        chacha20_qround_d60(x, 0, 5, 10, 15);
        chacha20_qround_d60(x, 1, 6, 11, 12);
        chacha20_qround_d60(x, 2, 7, 8, 13);
        chacha20_qround_d60(x, 3, 4, 9, 14);
    }
    for (int i = 0; i < 16; ++i) out[i] = x[i] + init[i];
}
