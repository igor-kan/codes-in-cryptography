/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Galois/Counter Mode (GCM) GHASH Block Field Multiply.
 * Module: gcm_ghash_block | Algorithm Family: ghash
 */

#ifndef GCM_GHASH_BLOCK_TYPES_H
#define GCM_GHASH_BLOCK_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define GCM_GHASH_BLOCK_ALIGNMENT 64
#define GCM_GHASH_BLOCK_CAPACITY 4096

typedef struct gcm_ghash_block_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} gcm_ghash_block_config_t;

typedef struct gcm_ghash_block_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    gcm_ghash_block_config_t config;
} gcm_ghash_block_state_t;

#endif /* GCM_GHASH_BLOCK_TYPES_H */
