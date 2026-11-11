/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct secp256k1_ecdsa_sync_counter {
    volatile uint64_t count;
} secp256k1_ecdsa_sync_counter_t;

static inline void secp256k1_ecdsa_sync_inc_v47(secp256k1_ecdsa_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
