#ifndef RABIN_MILLER_U64_D59_INTERFACE_H
#define RABIN_MILLER_U64_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

int is_prime_u64(uint64_t n);

rabin_miller_u64_d59_err_t rabin_miller_u64_d59_validate_len(size_t n);
uint64_t rabin_miller_u64_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t rabin_miller_u64_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
rabin_miller_u64_d59_err_t rabin_miller_u64_d59_verify_guard(bool cond);

#endif /* RABIN_MILLER_U64_D59_INTERFACE_H */
