/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct verifiable_secret_sharing_atomic_counter {
    volatile uint64_t value;
} verifiable_secret_sharing_atomic_counter_t;

static inline void verifiable_secret_sharing_counter_inc(verifiable_secret_sharing_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
