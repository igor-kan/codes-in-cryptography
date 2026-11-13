/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Constant-Time Square-and-Multiply Modular Exponentiation.
 * Module: modular_exponentiation_ladder | Algorithm Family: mod_exp
 */

#ifndef MODULAR_EXPONENTIATION_LADDER_TYPES_H
#define MODULAR_EXPONENTIATION_LADDER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MODULAR_EXPONENTIATION_LADDER_ALIGNMENT 64
#define MODULAR_EXPONENTIATION_LADDER_CAPACITY 2048

typedef struct modular_exponentiation_ladder_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} modular_exponentiation_ladder_config_t;

typedef struct modular_exponentiation_ladder_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    modular_exponentiation_ladder_config_t config;
} modular_exponentiation_ladder_state_t;

#endif /* MODULAR_EXPONENTIATION_LADDER_TYPES_H */
