/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm | Algorithm Family: sponge_state
 */

#ifndef KECCAK_P1600_PERM_TYPES_H
#define KECCAK_P1600_PERM_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define KECCAK_P1600_PERM_ALIGNMENT 64
#define KECCAK_P1600_PERM_BASE_CAPACITY 1024

typedef struct keccak_p1600_perm_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} keccak_p1600_perm_config_t;

typedef struct keccak_p1600_perm_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    keccak_p1600_perm_config_t config;
} keccak_p1600_perm_state_t;

#endif /* KECCAK_P1600_PERM_TYPES_H */
