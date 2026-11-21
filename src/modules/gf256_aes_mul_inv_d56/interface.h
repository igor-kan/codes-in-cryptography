#ifndef GF256_AES_MUL_INV_D56_INTERFACE_H
#define GF256_AES_MUL_INV_D56_INTERFACE_H

#include "types.h"
#include "errors.h"

uint8_t gf256_mul(uint8_t a, uint8_t b);
uint8_t gf256_inv(uint8_t a);

gf256_aes_mul_inv_d56_err_t gf256_aes_mul_inv_d56_validate_len(size_t n);
uint64_t gf256_aes_mul_inv_d56_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t gf256_aes_mul_inv_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
gf256_aes_mul_inv_d56_err_t gf256_aes_mul_inv_d56_verify_guard(bool cond);

#endif /* GF256_AES_MUL_INV_D56_INTERFACE_H */
