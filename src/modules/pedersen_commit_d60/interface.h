#ifndef PEDERSEN_COMMIT_D60_INTERFACE_H
#define PEDERSEN_COMMIT_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t pedersen_pow_d60(uint64_t base, uint64_t exp);
uint64_t pedersen_commit_d60(uint64_t v, uint64_t r);
bool pedersen_verify_d60(uint64_t c, uint64_t v, uint64_t r);

pedersen_commit_d60_err_t pedersen_commit_d60_validate_len(size_t n);
uint64_t pedersen_commit_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t pedersen_commit_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
pedersen_commit_d60_err_t pedersen_commit_d60_verify_guard(bool cond);

#endif /* PEDERSEN_COMMIT_D60_INTERFACE_H */
