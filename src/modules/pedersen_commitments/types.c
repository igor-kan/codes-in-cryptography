/**
 * @file types.c
 * @brief Core types and configuration for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

#ifndef PEDERSEN_COMMITMENTS_TYPES_H
#define PEDERSEN_COMMITMENTS_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define PEDERSEN_COMMITMENTS_ALIGNMENT 64
#define PEDERSEN_COMMITMENTS_CAPACITY 4096

typedef struct pedersen_commitments_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} pedersen_commitments_config_t;

typedef struct pedersen_commitments_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    pedersen_commitments_config_t config;
} pedersen_commitments_state_t;

#endif /* PEDERSEN_COMMITMENTS_TYPES_H */
