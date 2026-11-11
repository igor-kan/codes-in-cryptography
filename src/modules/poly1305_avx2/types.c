/**
 * @file types.c
 * @brief Core types and configuration for AVX2-Accelerated Poly1305 Message Authentication Code.
 * Module: poly1305_avx2
 */

#ifndef POLY1305_AVX2_TYPES_H
#define POLY1305_AVX2_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define POLY1305_AVX2_ALIGNMENT 64
#define POLY1305_AVX2_DEFAULT_SZ 8192

typedef struct poly1305_avx2_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} poly1305_avx2_config_t;

typedef struct poly1305_avx2_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    poly1305_avx2_config_t config;
} poly1305_avx2_state_t;

#endif /* POLY1305_AVX2_TYPES_H */
