#include "interface.h"
#include <string.h>

static inline uint64_t ror64(uint64_t x, int r) { return (x >> r) | (x << (64 - r)); }
static inline uint64_t rotl64(uint64_t x, int r) { return (x << r) | (x >> (64 - r)); }

#define ER64(x, y, k) do { x = ror64(x, 8); x += y; x ^= (k); y = rotl64(y, 3); y ^= x; } while(0)
#define DR64(x, y, k) do { y ^= x; y = ror64(y, 3); x ^= (k); x -= y; x = rotl64(x, 8); } while(0)

void speck128_ctr_cipher_expand(const uint64_t key[2], speck128_rk_t* out) {
    uint64_t b = key[0], a = key[1];
    out->rk[0] = b;
    for (uint64_t i = 0; i < SPECK128_ROUNDS - 1; ++i) {
        ER64(a, b, i);
        out->rk[i + 1] = b;
    }
}

void speck128_ctr_cipher_enc_block(const speck128_rk_t* rk, const uint64_t pt[2], uint64_t ct[2]) {
    uint64_t y = pt[0], x = pt[1];
    for (uint32_t i = 0; i < SPECK128_ROUNDS; ++i) ER64(x, y, rk->rk[i]);
    ct[0] = y; ct[1] = x;
}

void speck128_ctr_cipher_dec_block(const speck128_rk_t* rk, const uint64_t ct[2], uint64_t pt[2]) {
    uint64_t y = ct[0], x = ct[1];
    for (int i = SPECK128_ROUNDS - 1; i >= 0; --i) DR64(x, y, rk->rk[i]);
    pt[0] = y; pt[1] = x;
}

speck128_ctr_cipher_err_t speck128_ctr_cipher_ctr_crypt(const speck128_rk_t* rk, uint64_t iv_hi, uint64_t ctr, const uint8_t* in, uint8_t* out, size_t len) {
    if (!rk || (len > 0 && (!in || !out))) return SPECK128_CTR_CIPHER_ERR_NULL;
    size_t pos = 0;
    while (pos < len) {
        uint64_t inp[2] = {ctr++, iv_hi};
        uint64_t ks[2];
        speck128_ctr_cipher_enc_block(rk, inp, ks);
        uint8_t kbytes[16];
        memcpy(kbytes, ks, 16);
        size_t chunk = (len - pos < 16) ? (len - pos) : 16;
        for (size_t i = 0; i < chunk; ++i) out[pos + i] = (uint8_t)(in[pos + i] ^ kbytes[i]);
        pos += chunk;
    }
    return SPECK128_CTR_CIPHER_OK;
}
