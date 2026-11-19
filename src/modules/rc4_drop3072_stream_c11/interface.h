#ifndef RC4_DROP3072_STREAM_C11_INTERFACE_H
#define RC4_DROP3072_STREAM_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void rc4_drop_init(rc4_state_t* st, const uint8_t* key, size_t klen, size_t drop);
void rc4_xor(rc4_state_t* st, uint8_t* buf, size_t len);

rc4_drop3072_stream_c11_err_t rc4_drop3072_stream_c11_validate_len(size_t n);
uint64_t rc4_drop3072_stream_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t rc4_drop3072_stream_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
rc4_drop3072_stream_c11_err_t rc4_drop3072_stream_c11_verify_guard(bool cond);

#endif /* RC4_DROP3072_STREAM_C11_INTERFACE_H */
