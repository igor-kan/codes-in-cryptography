/**
 * @file types.c
 * @brief Core types and configuration for ML-DSA (Dilithium) NTT Polynomial Multiplier.
 * Module: dilithium_poly_mul
 */

#ifndef DILITHIUM_POLY_MUL_TYPES_H
#define DILITHIUM_POLY_MUL_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define DILITHIUM_POLY_MUL_ALIGNMENT 64
#define DILITHIUM_POLY_MUL_DEFAULT_CAPACITY 1024

typedef struct dilithium_poly_mul_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} dilithium_poly_mul_config_t;

typedef struct dilithium_poly_mul_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    dilithium_poly_mul_config_t config;
} dilithium_poly_mul_state_t;

#endif /* DILITHIUM_POLY_MUL_TYPES_H */
