/**
 * @file types.c
 * @brief Core types and configuration for Cryptographic SipHash-2-4 Pseudorandom Function.
 * Module: siphash_2_4
 */

#ifndef SIPHASH_2_4_TYPES_H
#define SIPHASH_2_4_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIPHASH_2_4_ALIGNMENT 64
#define SIPHASH_2_4_DEFAULT_CAPACITY 1024

typedef struct siphash_2_4_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} siphash_2_4_config_t;

typedef struct siphash_2_4_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    siphash_2_4_config_t config;
} siphash_2_4_state_t;

#endif /* SIPHASH_2_4_TYPES_H */
