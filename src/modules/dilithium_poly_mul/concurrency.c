/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for ML-DSA (Dilithium) NTT Polynomial Multiplier.
 * Module: dilithium_poly_mul
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct dilithium_poly_mul_atomic_counter {
    volatile uint64_t value;
} dilithium_poly_mul_atomic_counter_t;

static inline void dilithium_poly_mul_counter_inc(dilithium_poly_mul_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
