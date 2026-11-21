#ifndef SHAMIR_LAGRANGE_GF257_D56_INTERFACE_H
#define SHAMIR_LAGRANGE_GF257_D56_INTERFACE_H

#include "types.h"
#include "errors.h"

int gf257_eval_poly(const int *coeffs, int k, int x);
int gf257_reconstruct_secret(const gf257_share_t *shares, int k);

shamir_lagrange_gf257_d56_err_t shamir_lagrange_gf257_d56_validate_len(size_t n);
uint64_t shamir_lagrange_gf257_d56_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t shamir_lagrange_gf257_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
shamir_lagrange_gf257_d56_err_t shamir_lagrange_gf257_d56_verify_guard(bool cond);

#endif /* SHAMIR_LAGRANGE_GF257_D56_INTERFACE_H */
