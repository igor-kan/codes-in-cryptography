/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Lagrange Interpolation Secret Reconstruction GF(256).
 * Module: shamir_reconstruction_gf
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct shamir_reconstruction_gf_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} shamir_reconstruction_gf_sync_state_t;

static inline void shamir_reconstruction_gf_sync_increment(shamir_reconstruction_gf_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
