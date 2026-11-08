/**
 * @file types.c
 * @brief Core types and configuration for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

#ifndef X25519_DIFFIE_HELLMAN_TYPES_H
#define X25519_DIFFIE_HELLMAN_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define X25519_DIFFIE_HELLMAN_ALIGNMENT 64
#define X25519_DIFFIE_HELLMAN_DEFAULT_CAPACITY 1024

typedef struct x25519_diffie_hellman_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} x25519_diffie_hellman_config_t;

typedef struct x25519_diffie_hellman_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    x25519_diffie_hellman_config_t config;
} x25519_diffie_hellman_state_t;

#endif /* X25519_DIFFIE_HELLMAN_TYPES_H */
