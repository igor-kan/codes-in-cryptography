/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Constant-Time Poly1305 Clamping and Modular MAC.
 * Module: poly1305_clamp_ladder
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct poly1305_clamp_ladder_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} poly1305_clamp_ladder_atomic_state_t;

static inline void poly1305_clamp_ladder_atomic_increment(poly1305_clamp_ladder_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
