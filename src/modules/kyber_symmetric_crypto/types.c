/**
 * @file types.c
 * @brief Core types and configuration for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

#ifndef KYBER_SYMMETRIC_CRYPTO_TYPES_H
#define KYBER_SYMMETRIC_CRYPTO_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define KYBER_SYMMETRIC_CRYPTO_ALIGNMENT 64
#define KYBER_SYMMETRIC_CRYPTO_DEFAULT_SZ 8192

typedef struct kyber_symmetric_crypto_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} kyber_symmetric_crypto_config_t;

typedef struct kyber_symmetric_crypto_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    kyber_symmetric_crypto_config_t config;
} kyber_symmetric_crypto_state_t;

#endif /* KYBER_SYMMETRIC_CRYPTO_TYPES_H */
