#ifndef GF128_GHASH_MUL_D60_INTERFACE_H
#define GF128_GHASH_MUL_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

gf128_elem_t gf128_mul_d60(gf128_elem_t x, gf128_elem_t y);

gf128_ghash_mul_d60_err_t gf128_ghash_mul_d60_validate_len(size_t n);
uint64_t gf128_ghash_mul_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t gf128_ghash_mul_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
gf128_ghash_mul_d60_err_t gf128_ghash_mul_d60_verify_guard(bool cond);

#endif /* GF128_GHASH_MUL_D60_INTERFACE_H */
