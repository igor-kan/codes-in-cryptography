/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct verifiable_random_function_sync_counter {
    volatile uint64_t count;
} verifiable_random_function_sync_counter_t;

static inline void verifiable_random_function_sync_inc(verifiable_random_function_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
