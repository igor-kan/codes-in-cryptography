/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for GF(256) Lagrange Polynomial Secret Sharing Engine.
 * Module: shamir_secret_sharing
 */

#ifndef SHAMIR_SECRET_SHARING_TYPES_H
#define SHAMIR_SECRET_SHARING_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SHAMIR_SECRET_SHARING_ALIGNMENT 64
#define SHAMIR_SECRET_SHARING_SUCCESS 0
#define SHAMIR_SECRET_SHARING_ERR_NULL_PTR -1
#define SHAMIR_SECRET_SHARING_ERR_INVALID_PARAM -2
#define SHAMIR_SECRET_SHARING_ERR_OUT_OF_BOUNDS -3

typedef struct shamir_secret_sharing_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} shamir_secret_sharing_config_t;

typedef struct shamir_secret_sharing_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    shamir_secret_sharing_config_t config;
} shamir_secret_sharing_context_t;

int shamir_secret_sharing_init(shamir_secret_sharing_context_t* ctx, const shamir_secret_sharing_config_t* cfg);
int shamir_secret_sharing_destroy(shamir_secret_sharing_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* SHAMIR_SECRET_SHARING_TYPES_H */
