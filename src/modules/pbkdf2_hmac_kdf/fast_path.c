#include "interface.h"
pbkdf2_hmac_kdf_err_t pbkdf2_hmac_kdf_derive_fast(const uint8_t* pwd, size_t plen, const uint8_t* salt, size_t slen, uint32_t iterations, uint8_t* dk, size_t dklen) {
    return pbkdf2_hmac_kdf_derive(pwd, plen, salt, slen, iterations, dk, dklen);
}
