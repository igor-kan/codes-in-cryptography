#ifndef AES_SUBBYTES_SBOX_D59_INTERFACE_H
#define AES_SUBBYTES_SBOX_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

uint8_t aes_sbox_alg(uint8_t x);
uint8_t aes_inv_sbox_alg(uint8_t y);

aes_subbytes_sbox_d59_err_t aes_subbytes_sbox_d59_validate_len(size_t n);
uint64_t aes_subbytes_sbox_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t aes_subbytes_sbox_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
aes_subbytes_sbox_d59_err_t aes_subbytes_sbox_d59_verify_guard(bool cond);

#endif /* AES_SUBBYTES_SBOX_D59_INTERFACE_H */
