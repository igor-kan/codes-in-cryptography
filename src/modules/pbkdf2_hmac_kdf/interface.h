#ifndef PBKDF2_HMAC_KDF_INTERFACE_H
#define PBKDF2_HMAC_KDF_INTERFACE_H

#include "types.h"
#include "errors.h"

pbkdf2_hmac_kdf_err_t pbkdf2_hmac_kdf_derive(const uint8_t* pwd, size_t plen, const uint8_t* salt, size_t slen, uint32_t iterations, uint8_t* dk, size_t dklen);
pbkdf2_hmac_kdf_err_t pbkdf2_hmac_kdf_validate(uint32_t iterations, size_t dklen);
pbkdf2_hmac_kdf_err_t pbkdf2_hmac_kdf_derive_fast(const uint8_t* pwd, size_t plen, const uint8_t* salt, size_t slen, uint32_t iterations, uint8_t* dk, size_t dklen);
pbkdf2_hmac_kdf_err_t pbkdf2_hmac_kdf_verify_rfc(void);

#endif /* PBKDF2_HMAC_KDF_INTERFACE_H */
