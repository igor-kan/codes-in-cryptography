/**
 * @file types.c
 * @brief Core types and configuration for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

#ifndef VERIFIABLE_RANDOM_FUNCTION_TYPES_H
#define VERIFIABLE_RANDOM_FUNCTION_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define VERIFIABLE_RANDOM_FUNCTION_ALIGNMENT 64
#define VERIFIABLE_RANDOM_FUNCTION_CAPACITY 4096

typedef struct verifiable_random_function_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} verifiable_random_function_config_t;

typedef struct verifiable_random_function_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    verifiable_random_function_config_t config;
} verifiable_random_function_state_t;

#endif /* VERIFIABLE_RANDOM_FUNCTION_TYPES_H */
