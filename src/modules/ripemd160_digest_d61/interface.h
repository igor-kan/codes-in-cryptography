#ifndef RIPEMD160_DIGEST_D61_INTERFACE_H
#define RIPEMD160_DIGEST_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void ripemd160_init_d61(ripemd160_ctx_d61_t* ctx);
void ripemd160_update_d61(ripemd160_ctx_d61_t* ctx, const uint8_t* data, size_t len);
void ripemd160_final_d61(ripemd160_ctx_d61_t* ctx, uint8_t digest[20]);
void ripemd160_digest_d61(const uint8_t* data, size_t len, uint8_t digest[20]);

ripemd160_digest_d61_err_t ripemd160_digest_d61_validate_len(size_t n);
uint64_t ripemd160_digest_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t ripemd160_digest_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
ripemd160_digest_d61_err_t ripemd160_digest_d61_verify_guard(bool cond);

#endif /* RIPEMD160_DIGEST_D61_INTERFACE_H */
