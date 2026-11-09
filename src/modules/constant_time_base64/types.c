/**
 * @file types.c
 * @brief Core types and configuration for Side-Channel Immune Constant-Time Base64 Engine.
 * Module: constant_time_base64
 */

#ifndef CONSTANT_TIME_BASE64_TYPES_H
#define CONSTANT_TIME_BASE64_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CONSTANT_TIME_BASE64_ALIGNMENT 64
#define CONSTANT_TIME_BASE64_CAPACITY 2048

typedef struct constant_time_base64_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} constant_time_base64_config_t;

typedef struct constant_time_base64_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    constant_time_base64_config_t config;
} constant_time_base64_state_t;

#endif /* CONSTANT_TIME_BASE64_TYPES_H */
