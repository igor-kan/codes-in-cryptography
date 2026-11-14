/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for SHA-512 Message Schedule Expansion & Compression.
 * Module: sha512_compression_round
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct sha512_compression_round_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} sha512_compression_round_sync_state_t;

static inline void sha512_compression_round_sync_increment(sha512_compression_round_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
