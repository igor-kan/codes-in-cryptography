/**
 * @file types.c
 * @brief Core types and configuration for Constant-Time Tonelli-Shanks Quadratic Residue Solver.
 * Module: modular_sqrt_tonelli
 */

#ifndef MODULAR_SQRT_TONELLI_TYPES_H
#define MODULAR_SQRT_TONELLI_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MODULAR_SQRT_TONELLI_ALIGNMENT 64
#define MODULAR_SQRT_TONELLI_CAPACITY 2048

typedef struct modular_sqrt_tonelli_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} modular_sqrt_tonelli_config_t;

typedef struct modular_sqrt_tonelli_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    modular_sqrt_tonelli_config_t config;
} modular_sqrt_tonelli_state_t;

#endif /* MODULAR_SQRT_TONELLI_TYPES_H */
