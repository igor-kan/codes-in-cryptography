#ifndef POLLARD_KANGAROO_DLOG_INTERFACE_H
#define POLLARD_KANGAROO_DLOG_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t mul_mod64(uint64_t a, uint64_t b, uint64_t m);
uint64_t pow_mod64(uint64_t base, uint64_t exp, uint64_t m);
dlog_result_t kangaroo_solve(uint64_t g, uint64_t h, uint64_t p, uint64_t lo, uint64_t hi);
pollard_kangaroo_dlog_err_t validate_dlog_interval(uint64_t p, uint64_t lo, uint64_t hi);
uint64_t fast_jump_step(uint64_t x, const uint64_t jumps[32]);
void parallel_kangaroo_solve(uint64_t g, const uint64_t* targets, size_t n, uint64_t p, uint64_t lo, uint64_t hi, dlog_result_t* out);
pollard_kangaroo_dlog_err_t verify_dlog_solution(uint64_t g, uint64_t h, uint64_t p, const dlog_result_t* res);

#endif /* POLLARD_KANGAROO_DLOG_INTERFACE_H */
