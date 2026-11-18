#ifndef ELGAMAL_MULTIPLICATIVE_HOM_INTERFACE_H
#define ELGAMAL_MULTIPLICATIVE_HOM_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t elg_pow(uint64_t b, uint64_t e);
elg_cipher_t elg_encrypt(uint64_t pk, uint64_t m, uint64_t r);
uint64_t elg_decrypt(uint64_t sk, elg_cipher_t ct);
elg_cipher_t elg_hom_mul(elg_cipher_t a, elg_cipher_t b);

elgamal_multiplicative_hom_err_t elgamal_multiplicative_hom_validate_len(size_t n);
uint64_t elgamal_multiplicative_hom_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t elgamal_multiplicative_hom_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
elgamal_multiplicative_hom_err_t elgamal_multiplicative_hom_verify_guard(bool cond);

#endif /* ELGAMAL_MULTIPLICATIVE_HOM_INTERFACE_H */
