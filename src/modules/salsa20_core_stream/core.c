#include "interface.h"
#include <string.h>

static inline uint32_t rotl32(uint32_t a, int b) { return (a << b) | (a >> (32 - b)); }
static inline uint32_t ld32le(const uint8_t* p) {
    return (uint32_t)p[0] | ((uint32_t)p[1]<<8) | ((uint32_t)p[2]<<16) | ((uint32_t)p[3]<<24);
}
static inline void st32le(uint8_t* p, uint32_t v) {
    p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); p[2]=(uint8_t)(v>>16); p[3]=(uint8_t)(v>>24);
}

#define QR(a, b, c, d) do { \
    b ^= rotl32(a + d, 7);  c ^= rotl32(b + a, 9); \
    d ^= rotl32(c + b, 13); a ^= rotl32(d + c, 18); \
} while (0)

void salsa20_core_stream_block(uint32_t out[16], const uint32_t in[16]) {
    uint32_t x[16];
    memcpy(x, in, sizeof(x));
    for (int i = 0; i < 10; ++i) {
        QR(x[0], x[4], x[8], x[12]); QR(x[5], x[9], x[13], x[1]);
        QR(x[10], x[14], x[2], x[6]); QR(x[15], x[3], x[7], x[11]);
        QR(x[0], x[1], x[2], x[3]); QR(x[5], x[6], x[7], x[4]);
        QR(x[10], x[11], x[8], x[9]); QR(x[15], x[12], x[13], x[14]);
    }
    for (int i = 0; i < 16; ++i) out[i] = x[i] + in[i];
}

salsa20_core_stream_err_t salsa20_core_stream_xor(const uint8_t key[32], const uint8_t nonce[8], uint64_t ctr, const uint8_t* in, uint8_t* out, size_t len) {
    if (!key || !nonce || (len > 0 && (!in || !out))) return SALSA20_CORE_STREAM_ERR_NULL;
    uint32_t st[16] = {
        0x61707865U, ld32le(key), ld32le(key+4), ld32le(key+8),
        ld32le(key+12), 0x3320646eU, ld32le(nonce), ld32le(nonce+4),
        (uint32_t)ctr, (uint32_t)(ctr >> 32), 0x79622d32U, ld32le(key+16),
        ld32le(key+20), ld32le(key+24), ld32le(key+28), 0x6b206574U
    };
    size_t pos = 0;
    while (pos < len) {
        uint32_t blk[16];
        salsa20_core_stream_block(blk, st);
        uint8_t ks[64];
        for (int i = 0; i < 16; ++i) st32le(ks + i * 4, blk[i]);
        size_t chunk = (len - pos < 64) ? (len - pos) : 64;
        for (size_t k = 0; k < chunk; ++k) out[pos + k] = (uint8_t)(in[pos + k] ^ ks[k]);
        pos += chunk;
        st[8]++;
        if (st[8] == 0) st[9]++;
    }
    return SALSA20_CORE_STREAM_OK;
}
