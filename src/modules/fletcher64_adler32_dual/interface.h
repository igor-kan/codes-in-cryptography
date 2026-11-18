#ifndef FLETCHER64_ADLER32_DUAL_INTERFACE_H
#define FLETCHER64_ADLER32_DUAL_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t compute_adler32(const uint8_t* buf, size_t len);
uint64_t compute_fletcher64(const uint32_t* words, size_t count);

fletcher64_adler32_dual_err_t fletcher64_adler32_dual_validate_len(size_t n);
uint64_t fletcher64_adler32_dual_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t fletcher64_adler32_dual_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
fletcher64_adler32_dual_err_t fletcher64_adler32_dual_verify_guard(bool cond);

#endif /* FLETCHER64_ADLER32_DUAL_INTERFACE_H */
