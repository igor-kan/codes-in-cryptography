#ifndef MODEXP_MONT_LADDER_D57_INTERFACE_H
#define MODEXP_MONT_LADDER_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t mont_ladder_modexp(uint64_t base, uint64_t exp, uint64_t mod);

modexp_mont_ladder_d57_err_t modexp_mont_ladder_d57_validate_len(size_t n);
uint64_t modexp_mont_ladder_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t modexp_mont_ladder_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
modexp_mont_ladder_d57_err_t modexp_mont_ladder_d57_verify_guard(bool cond);

#endif /* MODEXP_MONT_LADDER_D57_INTERFACE_H */
