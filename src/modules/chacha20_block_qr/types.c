/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr | Algorithm Family: cipher_core
 */

#ifndef CHACHA20_BLOCK_QR_TYPES_H
#define CHACHA20_BLOCK_QR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CHACHA20_BLOCK_QR_ALIGNMENT 64
#define CHACHA20_BLOCK_QR_CAPACITY 2048

typedef struct chacha20_block_qr_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} chacha20_block_qr_config_t;

typedef struct chacha20_block_qr_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    chacha20_block_qr_config_t config;
} chacha20_block_qr_state_t;

#endif /* CHACHA20_BLOCK_QR_TYPES_H */
