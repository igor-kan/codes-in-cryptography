#ifndef HKDF_SHA256_RFC5869_INTERFACE_H
#define HKDF_SHA256_RFC5869_INTERFACE_H

#include "types.h"
#include "errors.h"

void hkdf_sha256_hash(const uint8_t* data, size_t len, uint8_t out[32]);
void hkdf_hmac_sha256(const uint8_t* key, size_t key_len, const uint8_t* msg, size_t msg_len, uint8_t out[32]);
hkdf_sha256_rfc5869_err_t hkdf_extract(const uint8_t* salt, size_t salt_len, const uint8_t* ikm, size_t ikm_len, uint8_t prk[32]);
hkdf_sha256_rfc5869_err_t hkdf_expand(const uint8_t prk[32], const uint8_t* info, size_t info_len, uint8_t* okm, size_t okm_len);
hkdf_sha256_rfc5869_err_t hkdf_validate_okm(size_t okm_len);
int hkdf_ct_equal(const uint8_t* a, const uint8_t* b, size_t n);
hkdf_sha256_rfc5869_err_t hkdf_batch_derive_mt(const uint8_t prk[32], size_t count, size_t okm_len, uint8_t* out_flat, size_t num_threads);
hkdf_sha256_rfc5869_err_t hkdf_verify_rfc5869_a1(void);

#endif /* HKDF_SHA256_RFC5869_INTERFACE_H */
