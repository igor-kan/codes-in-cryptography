/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct keccak_p1600_perm_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} keccak_p1600_perm_atomic_state_t;

static inline void keccak_p1600_perm_atomic_increment(keccak_p1600_perm_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
