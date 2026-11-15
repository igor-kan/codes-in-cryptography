#include "interface.h"
#include <assert.h>

int main(void) {
    // Official FIPS 197 AES S-Box values
    assert(gf256_aes_rijndael_sbox_ct(0x00) == 0x63U);
    assert(gf256_aes_rijndael_sbox_ct(0x53) == 0xEDU);
    assert(gf256_aes_rijndael_sbox_ct(0xFF) == 0x16U);
    assert(gf256_aes_rijndael_mul(0x57, 0x83) == 0xC1U); // FIPS 197 Sec 4.2 example
    assert(gf256_aes_rijndael_check_all_inverses() == GF256_AES_RIJNDAEL_OK);
    // FIPS 197 MixColumns known vector: db 13 53 45 -> 8e 4d a1 bc
    uint8_t col[4] = {0xdb, 0x13, 0x53, 0x45};
    gf256_aes_rijndael_mix_column(col);
    assert(col[0] == 0x8e && col[1] == 0x4d && col[2] == 0xa1 && col[3] == 0xbc);
    gf256_aes_rijndael_invmix_column(col);
    assert(col[0] == 0xdb && col[1] == 0x13 && col[2] == 0x53 && col[3] == 0x45);
    return 0;
}
