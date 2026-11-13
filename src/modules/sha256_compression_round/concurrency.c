/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct sha256_compression_round_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} sha256_compression_round_reentrant_lock_t;

static inline void sha256_compression_round_seq_advance(sha256_compression_round_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
