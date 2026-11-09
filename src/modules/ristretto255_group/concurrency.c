/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Prime-Order Group Abstraction over Curve25519.
 * Module: ristretto255_group
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct ristretto255_group_sync_counter {
    volatile uint64_t count;
} ristretto255_group_sync_counter_t;

static inline void ristretto255_group_sync_inc(ristretto255_group_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
