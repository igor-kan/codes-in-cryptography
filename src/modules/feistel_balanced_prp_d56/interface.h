#ifndef FEISTEL_BALANCED_PRP_D56_INTERFACE_H
#define FEISTEL_BALANCED_PRP_D56_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t feistel4_enc(uint64_t x, const uint32_t rk[4]);
uint64_t feistel4_dec(uint64_t x, const uint32_t rk[4]);

feistel_balanced_prp_d56_err_t feistel_balanced_prp_d56_validate_len(size_t n);
uint64_t feistel_balanced_prp_d56_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t feistel_balanced_prp_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
feistel_balanced_prp_d56_err_t feistel_balanced_prp_d56_verify_guard(bool cond);

#endif /* FEISTEL_BALANCED_PRP_D56_INTERFACE_H */
