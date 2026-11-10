/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Curve448 (Ed448) Goldilocks Point Arithmetic Ladder.
 * Module: curve448_goldilocks
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct curve448_goldilocks_sync_counter {
    volatile uint64_t count;
} curve448_goldilocks_sync_counter_t;

static inline void curve448_goldilocks_sync_inc(curve448_goldilocks_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
