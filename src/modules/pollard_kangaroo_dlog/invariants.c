#include "interface.h"

pollard_kangaroo_dlog_err_t verify_dlog_solution(uint64_t g, uint64_t h, uint64_t p, const dlog_result_t* res) {
    if (!res || !res->found) return POLLARD_KANGAROO_DLOG_ERR_INVARIANT;
    return pow_mod64(g, res->exponent, p) == (h % p) ? POLLARD_KANGAROO_DLOG_OK : POLLARD_KANGAROO_DLOG_ERR_INVARIANT;
}
