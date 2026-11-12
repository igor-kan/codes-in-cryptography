/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression | Algorithm Family: blake_round
 */

#ifndef BLAKE2S_COMPRESSION_TYPES_H
#define BLAKE2S_COMPRESSION_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BLAKE2S_COMPRESSION_ALIGNMENT 64
#define BLAKE2S_COMPRESSION_BASE_CAPACITY 1024

typedef struct blake2s_compression_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} blake2s_compression_config_t;

typedef struct blake2s_compression_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    blake2s_compression_config_t config;
} blake2s_compression_state_t;

#endif /* BLAKE2S_COMPRESSION_TYPES_H */
