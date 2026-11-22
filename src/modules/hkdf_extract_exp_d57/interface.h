#ifndef HKDF_EXTRACT_EXP_D57_INTERFACE_H
#define HKDF_EXTRACT_EXP_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t hkdf_extract64(const uint8_t *salt, size_t slen, const uint8_t *ikm, size_t ilen);
uint64_t hkdf_expand64(uint64_t prk, const uint8_t *info, size_t infolen, uint8_t counter);

hkdf_extract_exp_d57_err_t hkdf_extract_exp_d57_validate_len(size_t n);
uint64_t hkdf_extract_exp_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t hkdf_extract_exp_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
hkdf_extract_exp_d57_err_t hkdf_extract_exp_d57_verify_guard(bool cond);

#endif /* HKDF_EXTRACT_EXP_D57_INTERFACE_H */
