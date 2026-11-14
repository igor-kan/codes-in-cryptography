/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta | Algorithm Family: sponge_state
 */

#ifndef KECCAK_F1600_THETA_TYPES_H
#define KECCAK_F1600_THETA_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define KECCAK_F1600_THETA_ALIGNMENT 64
#define KECCAK_F1600_THETA_CAPACITY 4096

typedef struct keccak_f1600_theta_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} keccak_f1600_theta_config_t;

typedef struct keccak_f1600_theta_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    keccak_f1600_theta_config_t config;
} keccak_f1600_theta_state_t;

#endif /* KECCAK_F1600_THETA_TYPES_H */
