/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine | Algorithm Family: sponge_duplex
 */

#ifndef SPONGE_DUPLEX_ENGINE_TYPES_H
#define SPONGE_DUPLEX_ENGINE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SPONGE_DUPLEX_ENGINE_ALIGNMENT 64
#define SPONGE_DUPLEX_ENGINE_BASE_CAPACITY 1024

typedef struct sponge_duplex_engine_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} sponge_duplex_engine_config_t;

typedef struct sponge_duplex_engine_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    sponge_duplex_engine_config_t config;
} sponge_duplex_engine_state_t;

#endif /* SPONGE_DUPLEX_ENGINE_TYPES_H */
