/**
 * @file types.c
 * @brief Core types and configuration for Zero-Knowledge Inner Product Argument Verification.
 * Module: bulletproofs_inner_product
 */

#ifndef BULLETPROOFS_INNER_PRODUCT_TYPES_H
#define BULLETPROOFS_INNER_PRODUCT_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BULLETPROOFS_INNER_PRODUCT_ALIGNMENT 64
#define BULLETPROOFS_INNER_PRODUCT_DEFAULT_SZ 8192

typedef struct bulletproofs_inner_product_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} bulletproofs_inner_product_config_t;

typedef struct bulletproofs_inner_product_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    bulletproofs_inner_product_config_t config;
} bulletproofs_inner_product_state_t;

#endif /* BULLETPROOFS_INNER_PRODUCT_TYPES_H */
