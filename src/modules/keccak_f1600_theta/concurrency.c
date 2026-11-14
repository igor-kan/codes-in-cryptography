/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct keccak_f1600_theta_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} keccak_f1600_theta_sync_state_t;

static inline void keccak_f1600_theta_sync_increment(keccak_f1600_theta_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
