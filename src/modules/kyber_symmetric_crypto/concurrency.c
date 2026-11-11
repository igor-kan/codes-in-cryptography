/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct kyber_symmetric_crypto_sync_counter {
    volatile uint64_t count;
} kyber_symmetric_crypto_sync_counter_t;

static inline void kyber_symmetric_crypto_sync_inc_v47(kyber_symmetric_crypto_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
