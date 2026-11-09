/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Constant-Time Poly1305 One-Time Authentication MAC.
 * Module: poly1305_mac
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct poly1305_mac_sync_counter {
    volatile uint64_t count;
} poly1305_mac_sync_counter_t;

static inline void poly1305_mac_sync_inc(poly1305_mac_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
