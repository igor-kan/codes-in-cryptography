/**
 * @file types.c
 * @brief Core types and configuration for SIMD-Accelerated BLAKE2b Cryptographic Hashing Engine.
 * Module: blake2b_simd
 */

#ifndef BLAKE2B_SIMD_TYPES_H
#define BLAKE2B_SIMD_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BLAKE2B_SIMD_ALIGNMENT 64
#define BLAKE2B_SIMD_CAPACITY 4096

typedef struct blake2b_simd_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} blake2b_simd_config_t;

typedef struct blake2b_simd_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    blake2b_simd_config_t config;
} blake2b_simd_state_t;

#endif /* BLAKE2B_SIMD_TYPES_H */
