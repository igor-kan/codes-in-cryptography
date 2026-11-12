/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Luby-Rackoff 4-Round Balanced Feistel Block Cipher.
 * Module: feistel_cipher_round | Algorithm Family: feistel
 */

#ifndef FEISTEL_CIPHER_ROUND_TYPES_H
#define FEISTEL_CIPHER_ROUND_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FEISTEL_CIPHER_ROUND_ALIGNMENT 64
#define FEISTEL_CIPHER_ROUND_BASE_CAPACITY 1024

typedef struct feistel_cipher_round_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} feistel_cipher_round_config_t;

typedef struct feistel_cipher_round_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    feistel_cipher_round_config_t config;
} feistel_cipher_round_state_t;

#endif /* FEISTEL_CIPHER_ROUND_TYPES_H */
