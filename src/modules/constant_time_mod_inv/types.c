/**
 * @file types.c
 * @brief Core types and configuration for Constant-Time Modular Inverse via Bernstein-Yang Ladder.
 * Module: constant_time_mod_inv
 */

#ifndef CONSTANT_TIME_MOD_INV_TYPES_H
#define CONSTANT_TIME_MOD_INV_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CONSTANT_TIME_MOD_INV_ALIGNMENT 64
#define CONSTANT_TIME_MOD_INV_DEFAULT_SZ 8192

typedef struct constant_time_mod_inv_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} constant_time_mod_inv_config_t;

typedef struct constant_time_mod_inv_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    constant_time_mod_inv_config_t config;
} constant_time_mod_inv_state_t;

#endif /* CONSTANT_TIME_MOD_INV_TYPES_H */
