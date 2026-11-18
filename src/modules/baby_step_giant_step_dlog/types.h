#ifndef BABY_STEP_GIANT_STEP_DLOG_TYPES_H
#define BABY_STEP_GIANT_STEP_DLOG_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t val;
    uint32_t idx;
} bsgs_pair_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} baby_step_giant_step_dlog_meta_t;

#endif /* BABY_STEP_GIANT_STEP_DLOG_TYPES_H */
