/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Constant-Time Montgomery Reduction and Ladder.
 * Module: montgomery_arithmetic
 */

#ifndef MONTGOMERY_ARITHMETIC_TYPES_H
#define MONTGOMERY_ARITHMETIC_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MONTGOMERY_ARITHMETIC_ALIGNMENT 64
#define MONTGOMERY_ARITHMETIC_SUCCESS 0
#define MONTGOMERY_ARITHMETIC_ERR_NULL_PTR -1
#define MONTGOMERY_ARITHMETIC_ERR_INVALID_PARAM -2
#define MONTGOMERY_ARITHMETIC_ERR_OUT_OF_BOUNDS -3

typedef struct montgomery_arithmetic_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} montgomery_arithmetic_config_t;

typedef struct montgomery_arithmetic_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    montgomery_arithmetic_config_t config;
} montgomery_arithmetic_context_t;

int montgomery_arithmetic_init(montgomery_arithmetic_context_t* ctx, const montgomery_arithmetic_config_t* cfg);
int montgomery_arithmetic_destroy(montgomery_arithmetic_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* MONTGOMERY_ARITHMETIC_TYPES_H */
