/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Constant-Time Tonelli-Shanks Quadratic Residue Solver.
 * Module: modular_sqrt_tonelli
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct modular_sqrt_tonelli_sync_counter {
    volatile uint64_t count;
} modular_sqrt_tonelli_sync_counter_t;

static inline void modular_sqrt_tonelli_sync_inc(modular_sqrt_tonelli_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
