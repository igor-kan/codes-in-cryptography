/**
 * @file types.c
 * @brief Core types and configuration for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

#ifndef ML_KEM_POLY_VECTOR_TYPES_H
#define ML_KEM_POLY_VECTOR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ML_KEM_POLY_VECTOR_ALIGNMENT 64
#define ML_KEM_POLY_VECTOR_CAPACITY 4096

typedef struct ml_kem_poly_vector_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} ml_kem_poly_vector_config_t;

typedef struct ml_kem_poly_vector_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    ml_kem_poly_vector_config_t config;
} ml_kem_poly_vector_state_t;

#endif /* ML_KEM_POLY_VECTOR_TYPES_H */
