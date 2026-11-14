/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for ChaCha20-Poly1305 Authenticated Encryption (AEAD).
 * Module: chacha20_poly1305_aead | Algorithm Family: cipher_core
 */

#ifndef CHACHA20_POLY1305_AEAD_TYPES_H
#define CHACHA20_POLY1305_AEAD_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CHACHA20_POLY1305_AEAD_ALIGNMENT 64
#define CHACHA20_POLY1305_AEAD_CAPACITY 4096

typedef struct chacha20_poly1305_aead_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} chacha20_poly1305_aead_config_t;

typedef struct chacha20_poly1305_aead_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    chacha20_poly1305_aead_config_t config;
} chacha20_poly1305_aead_state_t;

#endif /* CHACHA20_POLY1305_AEAD_TYPES_H */
