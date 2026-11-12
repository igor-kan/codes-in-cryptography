/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct sponge_duplex_engine_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} sponge_duplex_engine_atomic_state_t;

static inline void sponge_duplex_engine_atomic_increment(sponge_duplex_engine_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
