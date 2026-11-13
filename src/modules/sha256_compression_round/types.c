/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round | Algorithm Family: sha256
 */

#ifndef SHA256_COMPRESSION_ROUND_TYPES_H
#define SHA256_COMPRESSION_ROUND_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SHA256_COMPRESSION_ROUND_ALIGNMENT 64
#define SHA256_COMPRESSION_ROUND_CAPACITY 2048

typedef struct sha256_compression_round_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} sha256_compression_round_config_t;

typedef struct sha256_compression_round_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    sha256_compression_round_config_t config;
} sha256_compression_round_state_t;

#endif /* SHA256_COMPRESSION_ROUND_TYPES_H */
