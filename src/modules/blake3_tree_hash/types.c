/**
 * @file types.c
 * @brief Core types and configuration for Parallel Tree-Hashing BLAKE3 Compression Function.
 * Module: blake3_tree_hash
 */

#ifndef BLAKE3_TREE_HASH_TYPES_H
#define BLAKE3_TREE_HASH_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BLAKE3_TREE_HASH_ALIGNMENT 64
#define BLAKE3_TREE_HASH_CAPACITY 2048

typedef struct blake3_tree_hash_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} blake3_tree_hash_config_t;

typedef struct blake3_tree_hash_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    blake3_tree_hash_config_t config;
} blake3_tree_hash_state_t;

#endif /* BLAKE3_TREE_HASH_TYPES_H */
