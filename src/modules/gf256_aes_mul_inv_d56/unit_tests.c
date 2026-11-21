#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(gf256_aes_mul_inv_d56_validate_len(1) == GF256_AES_MUL_INV_D56_OK);
    assert(gf256_mul(0x57u, 0x83u) == 0xC1u);
    assert(gf256_mul(0x53u, gf256_inv(0x53u)) == 1u);
    assert(gf256_inv(0) == 0);
    assert(gf256_aes_mul_inv_d56_verify_guard(true) == GF256_AES_MUL_INV_D56_OK);
    return 0;
}
