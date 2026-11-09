/**
 * @file types.c
 * @brief Core types and configuration for Cryptographic Merkle Patricia State Trie Engine.
 * Module: merkle_patricia_trie
 */

#ifndef MERKLE_PATRICIA_TRIE_TYPES_H
#define MERKLE_PATRICIA_TRIE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MERKLE_PATRICIA_TRIE_ALIGNMENT 64
#define MERKLE_PATRICIA_TRIE_CAPACITY 2048

typedef struct merkle_patricia_trie_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} merkle_patricia_trie_config_t;

typedef struct merkle_patricia_trie_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    merkle_patricia_trie_config_t config;
} merkle_patricia_trie_state_t;

#endif /* MERKLE_PATRICIA_TRIE_TYPES_H */
