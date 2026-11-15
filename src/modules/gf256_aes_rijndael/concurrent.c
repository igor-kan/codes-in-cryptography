#include "interface.h"
gf256_aes_rijndael_err_t gf256_aes_rijndael_batch_sbox(uint8_t* buf, size_t n) {
    if (!buf && n > 0) return GF256_AES_RIJNDAEL_ERR_NULL;
    for (size_t i = 0; i < n; ++i) buf[i] = gf256_aes_rijndael_sbox_ct(buf[i]);
    return GF256_AES_RIJNDAEL_OK;
}
