#ifndef BABY_STEP_GIANT_STEP_DLOG_INTERFACE_H
#define BABY_STEP_GIANT_STEP_DLOG_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t bsgs_pow_mod(uint64_t b, uint64_t e, uint64_t p);
int64_t shanks_bsgs_dlog(uint64_t g, uint64_t h, uint64_t p);

baby_step_giant_step_dlog_err_t baby_step_giant_step_dlog_validate_len(size_t n);
uint64_t baby_step_giant_step_dlog_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t baby_step_giant_step_dlog_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
baby_step_giant_step_dlog_err_t baby_step_giant_step_dlog_verify_guard(bool cond);

#endif /* BABY_STEP_GIANT_STEP_DLOG_INTERFACE_H */
