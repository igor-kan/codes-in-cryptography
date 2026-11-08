/**
 * @file types.c
 * @brief Core types and configuration for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

#ifndef VERIFIABLE_SECRET_SHARING_TYPES_H
#define VERIFIABLE_SECRET_SHARING_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define VERIFIABLE_SECRET_SHARING_ALIGNMENT 64
#define VERIFIABLE_SECRET_SHARING_DEFAULT_CAPACITY 1024

typedef struct verifiable_secret_sharing_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} verifiable_secret_sharing_config_t;

typedef struct verifiable_secret_sharing_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    verifiable_secret_sharing_config_t config;
} verifiable_secret_sharing_state_t;

#endif /* VERIFIABLE_SECRET_SHARING_TYPES_H */
