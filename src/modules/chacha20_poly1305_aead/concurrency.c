/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for ChaCha20-Poly1305 Authenticated Encryption (AEAD).
 * Module: chacha20_poly1305_aead
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct chacha20_poly1305_aead_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} chacha20_poly1305_aead_sync_state_t;

static inline void chacha20_poly1305_aead_sync_increment(chacha20_poly1305_aead_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
