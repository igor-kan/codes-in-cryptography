#ifndef TEA_CLASSIC_64_D58_INTERFACE_H
#define TEA_CLASSIC_64_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

void tea_encrypt(uint32_t v[2], const uint32_t k[4]);
void tea_decrypt(uint32_t v[2], const uint32_t k[4]);

tea_classic_64_d58_err_t tea_classic_64_d58_validate_len(size_t n);
uint64_t tea_classic_64_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t tea_classic_64_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
tea_classic_64_d58_err_t tea_classic_64_d58_verify_guard(bool cond);

#endif /* TEA_CLASSIC_64_D58_INTERFACE_H */
