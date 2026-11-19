#ifndef FEISTEL_LUBY_RACKOFF_C11_INTERFACE_H
#define FEISTEL_LUBY_RACKOFF_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t lr_encrypt64(lr_key_t k, uint64_t pt);
uint64_t lr_decrypt64(lr_key_t k, uint64_t ct);

feistel_luby_rackoff_c11_err_t feistel_luby_rackoff_c11_validate_len(size_t n);
uint64_t feistel_luby_rackoff_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t feistel_luby_rackoff_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
feistel_luby_rackoff_c11_err_t feistel_luby_rackoff_c11_verify_guard(bool cond);

#endif /* FEISTEL_LUBY_RACKOFF_C11_INTERFACE_H */
