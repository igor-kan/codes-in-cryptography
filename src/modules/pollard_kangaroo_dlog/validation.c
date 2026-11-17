#include "interface.h"

pollard_kangaroo_dlog_err_t validate_dlog_interval(uint64_t p, uint64_t lo, uint64_t hi) {
    if (p < 3 || lo > hi) return POLLARD_KANGAROO_DLOG_ERR_BOUNDS;
    return POLLARD_KANGAROO_DLOG_OK;
}
