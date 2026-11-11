/**
 * @file types.c
 * @brief Core types and configuration for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

#ifndef MERKLE_SUM_TREE_TYPES_H
#define MERKLE_SUM_TREE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MERKLE_SUM_TREE_ALIGNMENT 64
#define MERKLE_SUM_TREE_DEFAULT_SZ 8192

typedef struct merkle_sum_tree_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} merkle_sum_tree_config_t;

typedef struct merkle_sum_tree_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    merkle_sum_tree_config_t config;
} merkle_sum_tree_state_t;

#endif /* MERKLE_SUM_TREE_TYPES_H */
