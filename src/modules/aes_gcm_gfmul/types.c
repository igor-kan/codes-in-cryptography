/**
 * @file types.c
 * @brief Core types and configuration for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#ifndef AES_GCM_GFMUL_TYPES_H
#define AES_GCM_GFMUL_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define AES_GCM_GFMUL_ALIGNMENT 64
#define AES_GCM_GFMUL_DEFAULT_CAPACITY 1024

typedef struct aes_gcm_gfmul_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} aes_gcm_gfmul_config_t;

typedef struct aes_gcm_gfmul_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    aes_gcm_gfmul_config_t config;
} aes_gcm_gfmul_state_t;

#endif /* AES_GCM_GFMUL_TYPES_H */
