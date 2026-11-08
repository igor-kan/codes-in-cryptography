/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Append-Only Cryptographic Merkle Mountain Range.
 * Module: merkle_mountain_range
 */

#ifndef MERKLE_MOUNTAIN_RANGE_TYPES_H
#define MERKLE_MOUNTAIN_RANGE_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MERKLE_MOUNTAIN_RANGE_ALIGNMENT 64
#define MERKLE_MOUNTAIN_RANGE_SUCCESS 0
#define MERKLE_MOUNTAIN_RANGE_ERR_NULL_PTR -1
#define MERKLE_MOUNTAIN_RANGE_ERR_INVALID_PARAM -2
#define MERKLE_MOUNTAIN_RANGE_ERR_OUT_OF_BOUNDS -3

typedef struct merkle_mountain_range_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} merkle_mountain_range_config_t;

typedef struct merkle_mountain_range_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    merkle_mountain_range_config_t config;
} merkle_mountain_range_context_t;

int merkle_mountain_range_init(merkle_mountain_range_context_t* ctx, const merkle_mountain_range_config_t* cfg);
int merkle_mountain_range_destroy(merkle_mountain_range_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* MERKLE_MOUNTAIN_RANGE_TYPES_H */
