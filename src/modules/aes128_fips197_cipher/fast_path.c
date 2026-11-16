#include "interface.h"
#include <string.h>

void aes128_ctr_xor(const aes128_ctx_t* ctx, const uint8_t nonce_ctr[16], const uint8_t* in, uint8_t* out, size_t len) {
    uint8_t ctr[16], ks[16];
    memcpy(ctr, nonce_ctr, 16);
    for (size_t off = 0; off < len; off += 16U) {
        aes128_encrypt_block(ctx, ctr, ks);
        size_t take = (len - off < 16U) ? (len - off) : 16U;
        for (size_t i = 0; i < take; ++i) out[off + i] = in[off + i] ^ ks[i];
        for (int b = 15; b >= 0; --b) {
            if (++ctr[b] != 0) break;
        }
    }
}
