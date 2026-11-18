#ifndef SOLOVAY_STRASSEN_JACOBI_INTERFACE_H
#define SOLOVAY_STRASSEN_JACOBI_INTERFACE_H

#include "types.h"
#include "errors.h"

int jacobi_symbol(uint64_t a, uint64_t n);
bool solovay_strassen_prime(uint64_t n);

solovay_strassen_jacobi_err_t solovay_strassen_jacobi_validate_len(size_t n);
uint64_t solovay_strassen_jacobi_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t solovay_strassen_jacobi_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
solovay_strassen_jacobi_err_t solovay_strassen_jacobi_verify_guard(bool cond);

#endif /* SOLOVAY_STRASSEN_JACOBI_INTERFACE_H */
