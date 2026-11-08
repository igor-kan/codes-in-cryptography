/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Twisted Edwards Curve Ed25519 Point Addition Laws.
 * Module: ed25519_curve
 */

#ifndef ED25519_CURVE_TYPES_H
#define ED25519_CURVE_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ED25519_CURVE_ALIGNMENT 64
#define ED25519_CURVE_SUCCESS 0
#define ED25519_CURVE_ERR_NULL_PTR -1
#define ED25519_CURVE_ERR_INVALID_PARAM -2
#define ED25519_CURVE_ERR_OUT_OF_BOUNDS -3

typedef struct ed25519_curve_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} ed25519_curve_config_t;

typedef struct ed25519_curve_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    ed25519_curve_config_t config;
} ed25519_curve_context_t;

int ed25519_curve_init(ed25519_curve_context_t* ctx, const ed25519_curve_config_t* cfg);
int ed25519_curve_destroy(ed25519_curve_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* ED25519_CURVE_TYPES_H */
