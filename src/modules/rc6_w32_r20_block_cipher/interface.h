#ifndef RC6_W32_R20_BLOCK_CIPHER_INTERFACE_H
#define RC6_W32_R20_BLOCK_CIPHER_INTERFACE_H

#include "types.h"
#include "errors.h"

void rc6_key_setup(rc6_ctx_t* ctx, const uint32_t key[4]);
void rc6_encrypt_block(const rc6_ctx_t* ctx, const uint32_t pt[4], uint32_t ct[4]);
void rc6_decrypt_block(const rc6_ctx_t* ctx, const uint32_t ct[4], uint32_t pt[4]);

rc6_w32_r20_block_cipher_err_t rc6_w32_r20_block_cipher_validate_len(size_t n);
uint64_t rc6_w32_r20_block_cipher_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t rc6_w32_r20_block_cipher_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
rc6_w32_r20_block_cipher_err_t rc6_w32_r20_block_cipher_verify_guard(bool cond);

#endif /* RC6_W32_R20_BLOCK_CIPHER_INTERFACE_H */
