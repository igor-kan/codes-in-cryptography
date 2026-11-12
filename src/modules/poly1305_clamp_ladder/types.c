/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Constant-Time Poly1305 Clamping and Modular MAC.
 * Module: poly1305_clamp_ladder | Algorithm Family: poly_mac
 */

#ifndef POLY1305_CLAMP_LADDER_TYPES_H
#define POLY1305_CLAMP_LADDER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define POLY1305_CLAMP_LADDER_ALIGNMENT 64
#define POLY1305_CLAMP_LADDER_BASE_CAPACITY 1024

typedef struct poly1305_clamp_ladder_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} poly1305_clamp_ladder_config_t;

typedef struct poly1305_clamp_ladder_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    poly1305_clamp_ladder_config_t config;
} poly1305_clamp_ladder_state_t;

#endif /* POLY1305_CLAMP_LADDER_TYPES_H */
