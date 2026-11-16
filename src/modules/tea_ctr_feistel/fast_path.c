#include "interface.h"

void tea_ctr_stream(const tea_key_t* key, uint64_t nonce, const uint8_t* in, uint8_t* out, size_t len) {
    size_t off = 0;
    uint64_t ctr = 0;
    while (off < len) {
        uint64_t blk = nonce ^ ctr;
        uint32_t v[2] = {(uint32_t)(blk >> 32), (uint32_t)(blk & 0xFFFFFFFFULL)};
        tea_encrypt_block(key, v);
        uint8_t ks[8];
        for (int b = 0; b < 4; ++b) {
            ks[b]     = (uint8_t)((v[0] >> (24 - 8 * b)) & 0xFFU);
            ks[4 + b] = (uint8_t)((v[1] >> (24 - 8 * b)) & 0xFFU);
        }
        size_t take = (len - off < 8U) ? (len - off) : 8U;
        for (size_t i = 0; i < take; ++i) out[off + i] = in[off + i] ^ ks[i];
        off += take;
        ++ctr;
    }
}
