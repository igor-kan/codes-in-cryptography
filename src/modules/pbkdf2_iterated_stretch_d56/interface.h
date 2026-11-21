#ifndef PBKDF2_ITERATED_STRETCH_D56_INTERFACE_H
#define PBKDF2_ITERATED_STRETCH_D56_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t stretch_kdf64(const uint8_t *pass, size_t plen, const uint8_t *salt, size_t slen, uint32_t rounds);

pbkdf2_iterated_stretch_d56_err_t pbkdf2_iterated_stretch_d56_validate_len(size_t n);
uint64_t pbkdf2_iterated_stretch_d56_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t pbkdf2_iterated_stretch_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
pbkdf2_iterated_stretch_d56_err_t pbkdf2_iterated_stretch_d56_verify_guard(bool cond);

#endif /* PBKDF2_ITERATED_STRETCH_D56_INTERFACE_H */
