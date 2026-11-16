#ifndef TEA_CTR_FEISTEL_INTERFACE_H
#define TEA_CTR_FEISTEL_INTERFACE_H

#include "types.h"
#include "errors.h"

void tea_encrypt_block(const tea_key_t* key, uint32_t v[2]);
void tea_decrypt_block(const tea_key_t* key, uint32_t v[2]);
tea_ctr_feistel_err_t tea_validate_key(const tea_key_t* key);
void tea_ctr_stream(const tea_key_t* key, uint64_t nonce, const uint8_t* in, uint8_t* out, size_t len);
tea_ctr_feistel_err_t tea_batch_roundtrip_mt(const tea_key_t* key, size_t n_blocks, size_t num_threads);
tea_ctr_feistel_err_t tea_verify_involution(const tea_key_t* key, uint32_t v0, uint32_t v1);

#endif /* TEA_CTR_FEISTEL_INTERFACE_H */
