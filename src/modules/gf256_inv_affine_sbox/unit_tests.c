#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(gf256_inv_affine_sbox_validate_len(1) == GF256_INV_AFFINE_SBOX_OK);
    assert(aes_sbox_eval(0x00U) == 0x63U);
    assert(aes_sbox_eval(0x53U) == 0xedU);
    assert(gf256_mul(0x53U, gf256_inv(0x53U)) == 1U);
    assert(gf256_inv_affine_sbox_verify_guard(true) == GF256_INV_AFFINE_SBOX_OK);
    return 0;
}
