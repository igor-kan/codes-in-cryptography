/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Side-Channel Immune Constant-Time Base64 Engine.
 * Module: constant_time_base64
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct constant_time_base64_sync_counter {
    volatile uint64_t count;
} constant_time_base64_sync_counter_t;

static inline void constant_time_base64_sync_inc(constant_time_base64_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
