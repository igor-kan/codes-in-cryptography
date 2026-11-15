#include "interface.h"
pbkdf2_hmac_kdf_err_t pbkdf2_hmac_kdf_validate(uint32_t iterations, size_t dklen) {
    if (iterations == 0 || dklen == 0) return PBKDF2_HMAC_KDF_ERR_INVALID;
    return PBKDF2_HMAC_KDF_OK;
}
