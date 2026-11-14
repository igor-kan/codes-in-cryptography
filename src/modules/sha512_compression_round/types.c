/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for SHA-512 Message Schedule Expansion & Compression.
 * Module: sha512_compression_round | Algorithm Family: sha256
 */

#ifndef SHA512_COMPRESSION_ROUND_TYPES_H
#define SHA512_COMPRESSION_ROUND_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SHA512_COMPRESSION_ROUND_ALIGNMENT 64
#define SHA512_COMPRESSION_ROUND_CAPACITY 4096

typedef struct sha512_compression_round_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} sha512_compression_round_config_t;

typedef struct sha512_compression_round_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    sha512_compression_round_config_t config;
} sha512_compression_round_state_t;

#endif /* SHA512_COMPRESSION_ROUND_TYPES_H */
