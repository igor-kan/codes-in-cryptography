#ifndef SIPHASH_2_4_PRF_D60_INTERFACE_H
#define SIPHASH_2_4_PRF_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t siphash24_d60(uint64_t k0, uint64_t k1, const uint8_t* in, size_t len);

siphash_2_4_prf_d60_err_t siphash_2_4_prf_d60_validate_len(size_t n);
uint64_t siphash_2_4_prf_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t siphash_2_4_prf_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
siphash_2_4_prf_d60_err_t siphash_2_4_prf_d60_verify_guard(bool cond);

#endif /* SIPHASH_2_4_PRF_D60_INTERFACE_H */
