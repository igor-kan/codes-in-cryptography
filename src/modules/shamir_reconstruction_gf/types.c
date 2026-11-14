/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Lagrange Interpolation Secret Reconstruction GF(256).
 * Module: shamir_reconstruction_gf | Algorithm Family: secret_sharing
 */

#ifndef SHAMIR_RECONSTRUCTION_GF_TYPES_H
#define SHAMIR_RECONSTRUCTION_GF_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SHAMIR_RECONSTRUCTION_GF_ALIGNMENT 64
#define SHAMIR_RECONSTRUCTION_GF_CAPACITY 4096

typedef struct shamir_reconstruction_gf_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} shamir_reconstruction_gf_config_t;

typedef struct shamir_reconstruction_gf_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    shamir_reconstruction_gf_config_t config;
} shamir_reconstruction_gf_state_t;

#endif /* SHAMIR_RECONSTRUCTION_GF_TYPES_H */
