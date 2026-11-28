#ifndef MD5_STREAM_DIGEST_D61_INTERFACE_H
#define MD5_STREAM_DIGEST_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void md5_init_d61(md5_ctx_d61_t* ctx);
void md5_update_d61(md5_ctx_d61_t* ctx, const uint8_t* data, size_t len);
void md5_final_d61(md5_ctx_d61_t* ctx, uint8_t digest[16]);
void md5_digest_d61(const uint8_t* data, size_t len, uint8_t digest[16]);

md5_stream_digest_d61_err_t md5_stream_digest_d61_validate_len(size_t n);
uint64_t md5_stream_digest_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t md5_stream_digest_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
md5_stream_digest_d61_err_t md5_stream_digest_d61_verify_guard(bool cond);

#endif /* MD5_STREAM_DIGEST_D61_INTERFACE_H */
