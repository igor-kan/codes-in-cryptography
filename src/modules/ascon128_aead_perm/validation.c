#include "interface.h"
ascon128_aead_perm_err_t ascon128_aead_perm_validate(const uint8_t* key, const uint8_t* nonce) {
    return (key && nonce) ? ASCON128_AEAD_PERM_OK : ASCON128_AEAD_PERM_ERR_NULL;
}
