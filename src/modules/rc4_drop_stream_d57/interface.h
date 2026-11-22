#ifndef RC4_DROP_STREAM_D57_INTERFACE_H
#define RC4_DROP_STREAM_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

void rc4_drop_xor(const uint8_t *key, size_t klen, size_t drop_n, uint8_t *buf, size_t len);

rc4_drop_stream_d57_err_t rc4_drop_stream_d57_validate_len(size_t n);
uint64_t rc4_drop_stream_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t rc4_drop_stream_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
rc4_drop_stream_d57_err_t rc4_drop_stream_d57_verify_guard(bool cond);

#endif /* RC4_DROP_STREAM_D57_INTERFACE_H */
