#ifndef POLLARD_KANGAROO_DLOG_TYPES_H
#define POLLARD_KANGAROO_DLOG_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t exponent;
    uint64_t steps;
    bool found;
} dlog_result_t;

#endif /* POLLARD_KANGAROO_DLOG_TYPES_H */
