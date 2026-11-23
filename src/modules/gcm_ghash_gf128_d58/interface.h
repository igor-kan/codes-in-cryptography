#ifndef GCM_GHASH_GF128_D58_INTERFACE_H
#define GCM_GHASH_GF128_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t gf64_mul(uint64_t a, uint64_t b);
uint64_t ghash64_blocks(uint64_t h, const uint64_t *blocks, size_t n);

gcm_ghash_gf128_d58_err_t gcm_ghash_gf128_d58_validate_len(size_t n);
uint64_t gcm_ghash_gf128_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t gcm_ghash_gf128_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
gcm_ghash_gf128_d58_err_t gcm_ghash_gf128_d58_verify_guard(bool cond);

#endif /* GCM_GHASH_GF128_D58_INTERFACE_H */
