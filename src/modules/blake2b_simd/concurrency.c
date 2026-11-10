/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for SIMD-Accelerated BLAKE2b Cryptographic Hashing Engine.
 * Module: blake2b_simd
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct blake2b_simd_sync_counter {
    volatile uint64_t count;
} blake2b_simd_sync_counter_t;

static inline void blake2b_simd_sync_inc(blake2b_simd_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
