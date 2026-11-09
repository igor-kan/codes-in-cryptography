/**
 * @file types.c
 * @brief Core types and configuration for Falcon Lattice Fast Fourier Orthogonalization (LDL).
 * Module: falcon_fldl
 */

#ifndef FALCON_FLDL_TYPES_H
#define FALCON_FLDL_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FALCON_FLDL_ALIGNMENT 64
#define FALCON_FLDL_CAPACITY 2048

typedef struct falcon_fldl_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} falcon_fldl_config_t;

typedef struct falcon_fldl_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    falcon_fldl_config_t config;
} falcon_fldl_state_t;

#endif /* FALCON_FLDL_TYPES_H */
