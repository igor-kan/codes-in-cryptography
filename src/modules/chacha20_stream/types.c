/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Constant-Time ChaCha20 Quarter-Round Permutation.
 * Module: chacha20_stream
 */

#ifndef CHACHA20_STREAM_TYPES_H
#define CHACHA20_STREAM_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CHACHA20_STREAM_ALIGNMENT 64
#define CHACHA20_STREAM_SUCCESS 0
#define CHACHA20_STREAM_ERR_NULL_PTR -1
#define CHACHA20_STREAM_ERR_INVALID_PARAM -2
#define CHACHA20_STREAM_ERR_OUT_OF_BOUNDS -3

typedef struct chacha20_stream_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} chacha20_stream_config_t;

typedef struct chacha20_stream_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    chacha20_stream_config_t config;
} chacha20_stream_context_t;

int chacha20_stream_init(chacha20_stream_context_t* ctx, const chacha20_stream_config_t* cfg);
int chacha20_stream_destroy(chacha20_stream_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* CHACHA20_STREAM_TYPES_H */
