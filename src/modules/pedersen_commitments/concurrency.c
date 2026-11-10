/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct pedersen_commitments_sync_counter {
    volatile uint64_t count;
} pedersen_commitments_sync_counter_t;

static inline void pedersen_commitments_sync_inc(pedersen_commitments_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
