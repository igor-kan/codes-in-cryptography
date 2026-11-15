#include "interface.h"
void xtea_cbc_mac_encrypt_fast(const xtea_key_t* key, const uint32_t* in, uint32_t* out, size_t blocks) {
    for (size_t i = 0; i < blocks; ++i) {
        uint32_t v[2] = {in[2*i], in[2*i+1]};
        xtea_cbc_mac_encrypt_block(key, v);
        out[2*i] = v[0]; out[2*i+1] = v[1];
    }
}
