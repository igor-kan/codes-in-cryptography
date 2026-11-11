/**
 * @file types.c
 * @brief Core types and configuration for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

#ifndef SECP256K1_ECDSA_TYPES_H
#define SECP256K1_ECDSA_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SECP256K1_ECDSA_ALIGNMENT 64
#define SECP256K1_ECDSA_DEFAULT_SZ 8192

typedef struct secp256k1_ecdsa_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} secp256k1_ecdsa_config_t;

typedef struct secp256k1_ecdsa_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    secp256k1_ecdsa_config_t config;
} secp256k1_ecdsa_state_t;

#endif /* SECP256K1_ECDSA_TYPES_H */
