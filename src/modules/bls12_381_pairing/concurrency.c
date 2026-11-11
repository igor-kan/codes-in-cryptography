/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct bls12_381_pairing_sync_counter {
    volatile uint64_t count;
} bls12_381_pairing_sync_counter_t;

static inline void bls12_381_pairing_sync_inc_v47(bls12_381_pairing_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
