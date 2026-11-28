#ifndef THREEFISH256_ARX_D61_INTERFACE_H
#define THREEFISH256_ARX_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void threefish256_encrypt_d61(const uint64_t key[4], const uint64_t tweak[2], const uint64_t pt[4], uint64_t ct[4]);
void threefish256_decrypt_d61(const uint64_t key[4], const uint64_t tweak[2], const uint64_t ct[4], uint64_t pt[4]);

threefish256_arx_d61_err_t threefish256_arx_d61_validate_len(size_t n);
uint64_t threefish256_arx_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t threefish256_arx_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
threefish256_arx_d61_err_t threefish256_arx_d61_verify_guard(bool cond);

#endif /* THREEFISH256_ARX_D61_INTERFACE_H */
