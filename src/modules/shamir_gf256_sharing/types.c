/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing | Algorithm Family: secret_sharing
 */

#ifndef SHAMIR_GF256_SHARING_TYPES_H
#define SHAMIR_GF256_SHARING_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SHAMIR_GF256_SHARING_ALIGNMENT 64
#define SHAMIR_GF256_SHARING_CAPACITY 2048

typedef struct shamir_gf256_sharing_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} shamir_gf256_sharing_config_t;

typedef struct shamir_gf256_sharing_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    shamir_gf256_sharing_config_t config;
} shamir_gf256_sharing_state_t;

#endif /* SHAMIR_GF256_SHARING_TYPES_H */
