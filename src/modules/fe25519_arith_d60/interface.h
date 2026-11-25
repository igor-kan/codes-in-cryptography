#ifndef FE25519_ARITH_D60_INTERFACE_H
#define FE25519_ARITH_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

void fe25519_zero_d60(fe25519_d60_t* o, uint64_t v0);
void fe25519_add_d60(fe25519_d60_t* o, const fe25519_d60_t* a, const fe25519_d60_t* b);
void fe25519_mul_d60(fe25519_d60_t* o, const fe25519_d60_t* a, const fe25519_d60_t* b);

fe25519_arith_d60_err_t fe25519_arith_d60_validate_len(size_t n);
uint64_t fe25519_arith_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t fe25519_arith_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
fe25519_arith_d60_err_t fe25519_arith_d60_verify_guard(bool cond);

#endif /* FE25519_ARITH_D60_INTERFACE_H */
