/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct aes_gcm_gfmul_atomic_counter {
    volatile uint64_t value;
} aes_gcm_gfmul_atomic_counter_t;

static inline void aes_gcm_gfmul_counter_inc(aes_gcm_gfmul_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
