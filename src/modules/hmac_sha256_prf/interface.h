#ifndef HMAC_SHA256_PRF_INTERFACE_H
#define HMAC_SHA256_PRF_INTERFACE_H

#include "types.h"
#include "errors.h"

hmac_sha256_prf_err_t hmac_sha256_prf_mac(const uint8_t* key, size_t klen, const uint8_t* msg, size_t mlen, uint8_t out[32]);
hmac_sha256_prf_err_t hmac_sha256_prf_hkdf_expand(const uint8_t prk[32], const uint8_t* info, size_t ilen, uint8_t* okm, size_t olen);
int hmac_sha256_prf_ct_eq32(const uint8_t a[32], const uint8_t b[32]);
hmac_sha256_prf_err_t hmac_sha256_prf_validate_okm(size_t olen);
hmac_sha256_prf_err_t hmac_sha256_prf_mac_fast(const uint8_t* key, size_t klen, const uint8_t* msg, size_t mlen, uint8_t out[32]);
hmac_sha256_prf_err_t hmac_sha256_prf_batch(const uint8_t* key, size_t klen, const uint8_t** msgs, const size_t* lens, uint8_t out[][32], size_t n);
hmac_sha256_prf_err_t hmac_sha256_prf_verify_invariants(void);

#endif /* HMAC_SHA256_PRF_INTERFACE_H */
