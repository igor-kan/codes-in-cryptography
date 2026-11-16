#ifndef AES128_FIPS197_CIPHER_INTERFACE_H
#define AES128_FIPS197_CIPHER_INTERFACE_H

#include "types.h"
#include "errors.h"

void aes128_init(aes128_ctx_t* ctx, const uint8_t key[16]);
void aes128_encrypt_block(const aes128_ctx_t* ctx, const uint8_t in[16], uint8_t out[16]);
void aes128_decrypt_block(const aes128_ctx_t* ctx, const uint8_t in[16], uint8_t out[16]);
aes128_fips197_cipher_err_t aes128_validate_ctx(const aes128_ctx_t* ctx);
void aes128_ctr_xor(const aes128_ctx_t* ctx, const uint8_t nonce_ctr[16], const uint8_t* in, uint8_t* out, size_t len);
aes128_fips197_cipher_err_t aes128_batch_ctr_mt(const aes128_ctx_t* ctx, const uint8_t* in, uint8_t* out, size_t n_blocks, size_t num_threads);
aes128_fips197_cipher_err_t aes128_verify_fips197_b(void);

#endif /* AES128_FIPS197_CIPHER_INTERFACE_H */
