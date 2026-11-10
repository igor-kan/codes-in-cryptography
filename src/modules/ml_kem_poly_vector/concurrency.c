/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct ml_kem_poly_vector_sync_counter {
    volatile uint64_t count;
} ml_kem_poly_vector_sync_counter_t;

static inline void ml_kem_poly_vector_sync_inc(ml_kem_poly_vector_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
