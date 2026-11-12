/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Constant-Time GHASH 128-Bit Carryless Field Multiply.
 * Module: galois_counter_mul | Algorithm Family: ghash
 */

#ifndef GALOIS_COUNTER_MUL_TYPES_H
#define GALOIS_COUNTER_MUL_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define GALOIS_COUNTER_MUL_ALIGNMENT 64
#define GALOIS_COUNTER_MUL_BASE_CAPACITY 1024

typedef struct galois_counter_mul_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} galois_counter_mul_config_t;

typedef struct galois_counter_mul_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    galois_counter_mul_config_t config;
} galois_counter_mul_state_t;

#endif /* GALOIS_COUNTER_MUL_TYPES_H */
