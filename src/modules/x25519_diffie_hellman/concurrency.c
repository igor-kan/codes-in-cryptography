/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct x25519_diffie_hellman_atomic_counter {
    volatile uint64_t value;
} x25519_diffie_hellman_atomic_counter_t;

static inline void x25519_diffie_hellman_counter_inc(x25519_diffie_hellman_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
