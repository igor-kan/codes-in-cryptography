#ifndef FROST_THRESHOLD_COMBINE_INTERFACE_H
#define FROST_THRESHOLD_COMBINE_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t mod_add_q(uint64_t a, uint64_t b);
uint64_t mod_mul_q(uint64_t a, uint64_t b);
uint64_t mod_inv_q(uint64_t a);
uint64_t pow_mod_p(uint64_t base, uint64_t exp);
frost_threshold_combine_err_t frost_lagrange_coeff(const uint64_t* ids, size_t t, size_t idx, uint64_t* out_lam);
uint64_t frost_combine_partial_sigs(const uint64_t* ids, const uint64_t* z_parts, size_t t);
bool frost_verify_schnorr(uint64_t pk, uint64_t R, uint64_t c, uint64_t z);
frost_threshold_combine_err_t validate_signer_ids(const uint64_t* ids, size_t t);
void frost_parallel_eval_shares(const uint64_t* coeffs, size_t deg, const uint64_t* ids, uint64_t* out_shares, size_t n);
frost_threshold_combine_err_t verify_threshold_roundtrip(void);

#endif /* FROST_THRESHOLD_COMBINE_INTERFACE_H */
