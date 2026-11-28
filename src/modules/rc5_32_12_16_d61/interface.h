#ifndef RC5_32_12_16_D61_INTERFACE_H
#define RC5_32_12_16_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void rc5_setup_d61(rc5_ctx_d61_t* ctx, const uint8_t key[16]);
void rc5_encrypt_d61(const rc5_ctx_d61_t* ctx, const uint32_t in[2], uint32_t out[2]);
void rc5_decrypt_d61(const rc5_ctx_d61_t* ctx, const uint32_t in[2], uint32_t out[2]);

rc5_32_12_16_d61_err_t rc5_32_12_16_d61_validate_len(size_t n);
uint64_t rc5_32_12_16_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t rc5_32_12_16_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
rc5_32_12_16_d61_err_t rc5_32_12_16_d61_verify_guard(bool cond);

#endif /* RC5_32_12_16_D61_INTERFACE_H */
