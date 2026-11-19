#ifndef BLAKLEY_HYPERPLANE_SHARE_INTERFACE_H
#define BLAKLEY_HYPERPLANE_SHARE_INTERFACE_H

#include "types.h"
#include "errors.h"

hyperplane_share_t blak_deal_share(uint64_t s, uint64_t y0, uint64_t a, uint64_t b);
uint64_t blak_recover_secret(hyperplane_share_t s1, hyperplane_share_t s2);

blakley_hyperplane_share_err_t blakley_hyperplane_share_validate_len(size_t n);
uint64_t blakley_hyperplane_share_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t blakley_hyperplane_share_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
blakley_hyperplane_share_err_t blakley_hyperplane_share_verify_guard(bool cond);

#endif /* BLAKLEY_HYPERPLANE_SHARE_INTERFACE_H */
