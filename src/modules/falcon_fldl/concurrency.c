/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Falcon Lattice Fast Fourier Orthogonalization (LDL).
 * Module: falcon_fldl
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct falcon_fldl_sync_counter {
    volatile uint64_t count;
} falcon_fldl_sync_counter_t;

static inline void falcon_fldl_sync_inc(falcon_fldl_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
