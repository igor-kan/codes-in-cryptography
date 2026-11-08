/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Cryptographic SipHash-2-4 Pseudorandom Function.
 * Module: siphash_2_4
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct siphash_2_4_atomic_counter {
    volatile uint64_t value;
} siphash_2_4_atomic_counter_t;

static inline void siphash_2_4_counter_inc(siphash_2_4_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
