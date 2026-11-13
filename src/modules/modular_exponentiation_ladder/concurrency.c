/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Constant-Time Square-and-Multiply Modular Exponentiation.
 * Module: modular_exponentiation_ladder
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct modular_exponentiation_ladder_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} modular_exponentiation_ladder_reentrant_lock_t;

static inline void modular_exponentiation_ladder_seq_advance(modular_exponentiation_ladder_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
