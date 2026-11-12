/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Luby-Rackoff 4-Round Balanced Feistel Block Cipher.
 * Module: feistel_cipher_round
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct feistel_cipher_round_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} feistel_cipher_round_atomic_state_t;

static inline void feistel_cipher_round_atomic_increment(feistel_cipher_round_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
