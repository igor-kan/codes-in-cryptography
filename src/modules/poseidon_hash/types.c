/**
 * @file types.c
 * @brief Core types and configuration for Zero-Knowledge Friendly Algebraic Poseidon Hash.
 * Module: poseidon_hash
 */

#ifndef POSEIDON_HASH_TYPES_H
#define POSEIDON_HASH_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define POSEIDON_HASH_ALIGNMENT 64
#define POSEIDON_HASH_CAPACITY 2048

typedef struct poseidon_hash_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} poseidon_hash_config_t;

typedef struct poseidon_hash_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    poseidon_hash_config_t config;
} poseidon_hash_state_t;

#endif /* POSEIDON_HASH_TYPES_H */
