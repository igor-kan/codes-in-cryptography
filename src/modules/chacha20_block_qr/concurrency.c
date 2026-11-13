/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct chacha20_block_qr_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} chacha20_block_qr_reentrant_lock_t;

static inline void chacha20_block_qr_seq_advance(chacha20_block_qr_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
