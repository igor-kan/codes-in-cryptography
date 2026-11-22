#ifndef SPECK64_128_ARX_D57_INTERFACE_H
#define SPECK64_128_ARX_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

void speck64_expand(const uint32_t k[4], uint32_t rk[27]);
void speck64_enc(uint32_t ct[2], const uint32_t rk[27]);
void speck64_dec(uint32_t pt[2], const uint32_t rk[27]);

speck64_128_arx_d57_err_t speck64_128_arx_d57_validate_len(size_t n);
uint64_t speck64_128_arx_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t speck64_128_arx_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
speck64_128_arx_d57_err_t speck64_128_arx_d57_verify_guard(bool cond);

#endif /* SPECK64_128_ARX_D57_INTERFACE_H */
