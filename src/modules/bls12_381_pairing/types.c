/**
 * @file types.c
 * @brief Core types and configuration for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

#ifndef BLS12_381_PAIRING_TYPES_H
#define BLS12_381_PAIRING_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BLS12_381_PAIRING_ALIGNMENT 64
#define BLS12_381_PAIRING_DEFAULT_SZ 8192

typedef struct bls12_381_pairing_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} bls12_381_pairing_config_t;

typedef struct bls12_381_pairing_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    bls12_381_pairing_config_t config;
} bls12_381_pairing_state_t;

#endif /* BLS12_381_PAIRING_TYPES_H */
