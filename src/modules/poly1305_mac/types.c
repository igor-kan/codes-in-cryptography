/**
 * @file types.c
 * @brief Core types and configuration for Constant-Time Poly1305 One-Time Authentication MAC.
 * Module: poly1305_mac
 */

#ifndef POLY1305_MAC_TYPES_H
#define POLY1305_MAC_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define POLY1305_MAC_ALIGNMENT 64
#define POLY1305_MAC_CAPACITY 2048

typedef struct poly1305_mac_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} poly1305_mac_config_t;

typedef struct poly1305_mac_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    poly1305_mac_config_t config;
} poly1305_mac_state_t;

#endif /* POLY1305_MAC_TYPES_H */
