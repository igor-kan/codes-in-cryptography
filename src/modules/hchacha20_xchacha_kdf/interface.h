#ifndef HCHACHA20_XCHACHA_KDF_INTERFACE_H
#define HCHACHA20_XCHACHA_KDF_INTERFACE_H

#include "types.h"
#include "errors.h"

hchacha20_xchacha_kdf_err_t hchacha20_derive(const uint8_t key[32], const uint8_t nonce16[16], uint8_t out_subkey[32]);
hchacha20_xchacha_kdf_err_t hchacha20_validate_ptrs(const uint8_t* k, const uint8_t* n, const uint8_t* out);
void hchacha20_fast_qr(uint32_t s[16], int a, int b, int c, int d);
void hchacha20_parallel_derive(const uint8_t key[32], const uint8_t* nonces16, size_t count, uint8_t* out_keys32);
hchacha20_xchacha_kdf_err_t hchacha20_verify_rfc_vector(void);

#endif /* HCHACHA20_XCHACHA_KDF_INTERFACE_H */
