#ifndef SIMON64_128_BIT_D57_INTERFACE_H
#define SIMON64_128_BIT_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

void simon64_expand(const uint32_t k[4], uint32_t rk[44]);
void simon64_enc(uint32_t v[2], const uint32_t rk[44]);
void simon64_dec(uint32_t v[2], const uint32_t rk[44]);

simon64_128_bit_d57_err_t simon64_128_bit_d57_validate_len(size_t n);
uint64_t simon64_128_bit_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t simon64_128_bit_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
simon64_128_bit_d57_err_t simon64_128_bit_d57_verify_guard(bool cond);

#endif /* SIMON64_128_BIT_D57_INTERFACE_H */
