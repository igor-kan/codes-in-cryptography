#include "interface.h"

void simon64_fast_ecb_xor(const simon64_key_t* ks, uint64_t* blocks, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        uint32_t in[2] = {(uint32_t)blocks[i], (uint32_t)(blocks[i] >> 32)};
        uint32_t out[2];
        simon64_encrypt_block(ks, in, out);
        blocks[i] = ((uint64_t)out[1] << 32) | out[0];
    }
}
