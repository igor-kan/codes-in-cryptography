/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Montgomery Ladder Scalar Multiplication on Curves.
 * Module: montgomery_ladder_curve
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct montgomery_ladder_curve_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} montgomery_ladder_curve_sync_state_t;

static inline void montgomery_ladder_curve_sync_increment(montgomery_ladder_curve_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
