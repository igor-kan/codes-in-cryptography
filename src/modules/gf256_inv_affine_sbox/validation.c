#include "interface.h"

gf256_inv_affine_sbox_err_t gf256_inv_affine_sbox_validate_len(size_t n) {
    if (n == 0) {
        return GF256_INV_AFFINE_SBOX_ERR_INVALID;
    }
    return GF256_INV_AFFINE_SBOX_OK;
}
