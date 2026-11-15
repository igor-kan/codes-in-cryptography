#include "interface.h"
pbkdf2_hmac_kdf_err_t pbkdf2_hmac_kdf_derive_pair(const uint8_t* pwd, size_t plen, const uint8_t* salt, size_t slen, uint32_t c, uint8_t dk1[32], uint8_t dk2[32]) {
    pbkdf2_hmac_kdf_err_t e = pbkdf2_hmac_kdf_derive(pwd, plen, salt, slen, c, dk1, 32);
    if (e != PBKDF2_HMAC_KDF_OK) return e;
    return pbkdf2_hmac_kdf_derive(pwd, plen, salt, slen, c, dk2, 32);
}
