/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Montgomery Ladder Scalar Multiplication on Curves.
 * Module: montgomery_ladder_curve | Algorithm Family: mod_exp
 */

#ifndef MONTGOMERY_LADDER_CURVE_TYPES_H
#define MONTGOMERY_LADDER_CURVE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MONTGOMERY_LADDER_CURVE_ALIGNMENT 64
#define MONTGOMERY_LADDER_CURVE_CAPACITY 4096

typedef struct montgomery_ladder_curve_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} montgomery_ladder_curve_config_t;

typedef struct montgomery_ladder_curve_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    montgomery_ladder_curve_config_t config;
} montgomery_ladder_curve_state_t;

#endif /* MONTGOMERY_LADDER_CURVE_TYPES_H */
