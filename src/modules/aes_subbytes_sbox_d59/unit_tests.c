#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(aes_subbytes_sbox_d59_validate_len(1) == AES_SUBBYTES_SBOX_D59_OK);
    assert(aes_sbox_alg(0x00u) == 0x63u && aes_sbox_alg(0x53u) == 0xEDu);
    for (int i = 0; i < 256; ++i) {
        assert(aes_inv_sbox_alg(aes_sbox_alg((uint8_t)i)) == (uint8_t)i);
    }
    assert(aes_subbytes_sbox_d59_verify_guard(true) == AES_SUBBYTES_SBOX_D59_OK);
    return 0;
}
