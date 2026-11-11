/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Constant-Time Modular Inverse via Bernstein-Yang Ladder.
 * Module: constant_time_mod_inv
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct constant_time_mod_inv_sync_counter {
    volatile uint64_t count;
} constant_time_mod_inv_sync_counter_t;

static inline void constant_time_mod_inv_sync_inc_v47(constant_time_mod_inv_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
