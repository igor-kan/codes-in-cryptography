#include "interface.h"

gf256_aes_mul_inv_d56_err_t gf256_aes_mul_inv_d56_verify_guard(bool cond) {
    if (!cond) {
        return GF256_AES_MUL_INV_D56_ERR_INVARIANT;
    }
    return GF256_AES_MUL_INV_D56_OK;
}
