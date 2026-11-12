/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct blake2s_compression_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} blake2s_compression_atomic_state_t;

static inline void blake2s_compression_atomic_increment(blake2s_compression_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
