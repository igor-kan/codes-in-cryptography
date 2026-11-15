#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t d1[40], d2[20];
    assert(pbkdf2_hmac_kdf_derive((const uint8_t*)"pw", 2, (const uint8_t*)"s", 1, 10, d1, 40) == PBKDF2_HMAC_KDF_OK);
    assert(pbkdf2_hmac_kdf_derive((const uint8_t*)"pw", 2, (const uint8_t*)"s", 1, 10, d2, 20) == PBKDF2_HMAC_KDF_OK);
    assert(memcmp(d1, d2, 20) == 0); // Prefix consistency invariant
    assert(pbkdf2_hmac_kdf_validate(0, 32) == PBKDF2_HMAC_KDF_ERR_INVALID);
    return 0;
}
