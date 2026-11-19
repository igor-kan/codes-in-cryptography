#ifndef ELGAMAL_SCHNORR_ZKP_INTERFACE_H
#define ELGAMAL_SCHNORR_ZKP_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t zkp_pow_p(uint64_t b, uint64_t e);
schnorr_zkp_t schnorr_prove(uint64_t sk, uint64_t nonce_k, uint64_t msg);
bool schnorr_verify(uint64_t pk, uint64_t msg, schnorr_zkp_t sig);

elgamal_schnorr_zkp_err_t elgamal_schnorr_zkp_validate_len(size_t n);
uint64_t elgamal_schnorr_zkp_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t elgamal_schnorr_zkp_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
elgamal_schnorr_zkp_err_t elgamal_schnorr_zkp_verify_guard(bool cond);

#endif /* ELGAMAL_SCHNORR_ZKP_INTERFACE_H */
