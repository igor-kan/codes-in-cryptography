/**
 * @file types.c
 * @brief Core types and configuration for Prime-Order Group Abstraction over Curve25519.
 * Module: ristretto255_group
 */

#ifndef RISTRETTO255_GROUP_TYPES_H
#define RISTRETTO255_GROUP_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define RISTRETTO255_GROUP_ALIGNMENT 64
#define RISTRETTO255_GROUP_CAPACITY 2048

typedef struct ristretto255_group_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} ristretto255_group_config_t;

typedef struct ristretto255_group_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    ristretto255_group_config_t config;
} ristretto255_group_state_t;

#endif /* RISTRETTO255_GROUP_TYPES_H */
