#include "interface.h"

gf256_inv_affine_sbox_err_t gf256_inv_affine_sbox_verify_guard(bool cond) {
    if (!cond) {
        return GF256_INV_AFFINE_SBOX_ERR_INVARIANT;
    }
    return GF256_INV_AFFINE_SBOX_OK;
}
