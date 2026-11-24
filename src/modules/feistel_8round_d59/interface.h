#ifndef FEISTEL_8ROUND_D59_INTERFACE_H
#define FEISTEL_8ROUND_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t feistel8_enc(uint64_t pt, const uint32_t rk[8]);
uint64_t feistel8_dec(uint64_t ct, const uint32_t rk[8]);

feistel_8round_d59_err_t feistel_8round_d59_validate_len(size_t n);
uint64_t feistel_8round_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t feistel_8round_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
feistel_8round_d59_err_t feistel_8round_d59_verify_guard(bool cond);

#endif /* FEISTEL_8ROUND_D59_INTERFACE_H */
