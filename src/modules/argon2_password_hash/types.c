/**
 * @file types.c
 * @brief Core types and configuration for Memory-Hard Argon2d/Argon2i Block Mixing Permutation.
 * Module: argon2_password_hash
 */

#ifndef ARGON2_PASSWORD_HASH_TYPES_H
#define ARGON2_PASSWORD_HASH_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ARGON2_PASSWORD_HASH_ALIGNMENT 64
#define ARGON2_PASSWORD_HASH_DEFAULT_SZ 8192

typedef struct argon2_password_hash_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} argon2_password_hash_config_t;

typedef struct argon2_password_hash_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    argon2_password_hash_config_t config;
} argon2_password_hash_state_t;

#endif /* ARGON2_PASSWORD_HASH_TYPES_H */
