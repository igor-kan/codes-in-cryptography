/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Zero-Knowledge Friendly Algebraic Poseidon Hash.
 * Module: poseidon_hash
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct poseidon_hash_sync_counter {
    volatile uint64_t count;
} poseidon_hash_sync_counter_t;

static inline void poseidon_hash_sync_inc(poseidon_hash_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
