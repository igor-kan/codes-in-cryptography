/**
 * @file types.c
 * @brief Core types and configuration for Curve448 (Ed448) Goldilocks Point Arithmetic Ladder.
 * Module: curve448_goldilocks
 */

#ifndef CURVE448_GOLDILOCKS_TYPES_H
#define CURVE448_GOLDILOCKS_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CURVE448_GOLDILOCKS_ALIGNMENT 64
#define CURVE448_GOLDILOCKS_CAPACITY 4096

typedef struct curve448_goldilocks_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} curve448_goldilocks_config_t;

typedef struct curve448_goldilocks_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    curve448_goldilocks_config_t config;
} curve448_goldilocks_state_t;

#endif /* CURVE448_GOLDILOCKS_TYPES_H */
