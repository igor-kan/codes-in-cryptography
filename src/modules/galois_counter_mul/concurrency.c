/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Constant-Time GHASH 128-Bit Carryless Field Multiply.
 * Module: galois_counter_mul
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct galois_counter_mul_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} galois_counter_mul_atomic_state_t;

static inline void galois_counter_mul_atomic_increment(galois_counter_mul_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
