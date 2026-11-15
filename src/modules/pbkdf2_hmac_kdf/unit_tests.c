#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    assert(pbkdf2_hmac_kdf_verify_rfc() == PBKDF2_HMAC_KDF_OK);
    // Test c=2 vector: ("password", "salt", c=2, dkLen=32) = ae4d0c95...
    const uint8_t exp_c2[4] = {0xae, 0x4d, 0x0c, 0x95};
    uint8_t dk[32];
    assert(pbkdf2_hmac_kdf_derive((const uint8_t*)"password", 8, (const uint8_t*)"salt", 4, 2, dk, 32) == PBKDF2_HMAC_KDF_OK);
    assert(memcmp(dk, exp_c2, 4) == 0);
    return 0;
}
