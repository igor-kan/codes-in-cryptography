/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Galois/Counter Mode (GCM) GHASH Block Field Multiply.
 * Module: gcm_ghash_block
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct gcm_ghash_block_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} gcm_ghash_block_sync_state_t;

static inline void gcm_ghash_block_sync_increment(gcm_ghash_block_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
