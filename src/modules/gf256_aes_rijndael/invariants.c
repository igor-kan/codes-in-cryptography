#include "interface.h"
gf256_aes_rijndael_err_t gf256_aes_rijndael_check_all_inverses(void) {
    if (gf256_aes_rijndael_inv(0) != 0) return GF256_AES_RIJNDAEL_ERR_INVARIANT;
    for (int a = 1; a <= 255; ++a) {
        uint8_t inv = gf256_aes_rijndael_inv((uint8_t)a);
        if (gf256_aes_rijndael_mul((uint8_t)a, inv) != 1U) return GF256_AES_RIJNDAEL_ERR_INVARIANT;
        uint8_t s = gf256_aes_rijndael_sbox_ct((uint8_t)a);
        if (gf256_aes_rijndael_invsbox_ct(s) != (uint8_t)a) return GF256_AES_RIJNDAEL_ERR_INVARIANT;
    }
    return GF256_AES_RIJNDAEL_OK;
}
