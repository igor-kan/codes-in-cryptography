#include "interface.h"

gf256_aes_mul_inv_d56_err_t gf256_aes_mul_inv_d56_validate_len(size_t n) {
    if (n == 0) {
        return GF256_AES_MUL_INV_D56_ERR_INVALID;
    }
    return GF256_AES_MUL_INV_D56_OK;
}
