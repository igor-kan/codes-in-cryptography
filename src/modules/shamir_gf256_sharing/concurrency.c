/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct shamir_gf256_sharing_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} shamir_gf256_sharing_reentrant_lock_t;

static inline void shamir_gf256_sharing_seq_advance(shamir_gf256_sharing_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
