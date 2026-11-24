#ifndef LFSR_GALOIS32_D59_INTERFACE_H
#define LFSR_GALOIS32_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t galois32_step(uint32_t *st);

lfsr_galois32_d59_err_t lfsr_galois32_d59_validate_len(size_t n);
uint64_t lfsr_galois32_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t lfsr_galois32_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
lfsr_galois32_d59_err_t lfsr_galois32_d59_verify_guard(bool cond);

#endif /* LFSR_GALOIS32_D59_INTERFACE_H */
