#ifndef GIMLI_24ROUND_SPBOX_PERM_INTERFACE_H
#define GIMLI_24ROUND_SPBOX_PERM_INTERFACE_H

#include "types.h"
#include "errors.h"

void gimli_permute(gimli_state_t* st);

gimli_24round_spbox_perm_err_t gimli_24round_spbox_perm_validate_len(size_t n);
uint64_t gimli_24round_spbox_perm_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t gimli_24round_spbox_perm_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
gimli_24round_spbox_perm_err_t gimli_24round_spbox_perm_verify_guard(bool cond);

#endif /* GIMLI_24ROUND_SPBOX_PERM_INTERFACE_H */
