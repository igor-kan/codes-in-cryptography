/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Kate Polynomial Commitment and Proof Verification.
 * Module: kzg_commitments
 */

#ifndef KZG_COMMITMENTS_TYPES_H
#define KZG_COMMITMENTS_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define KZG_COMMITMENTS_ALIGNMENT 64
#define KZG_COMMITMENTS_SUCCESS 0
#define KZG_COMMITMENTS_ERR_NULL_PTR -1
#define KZG_COMMITMENTS_ERR_INVALID_PARAM -2
#define KZG_COMMITMENTS_ERR_OUT_OF_BOUNDS -3

typedef struct kzg_commitments_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} kzg_commitments_config_t;

typedef struct kzg_commitments_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    kzg_commitments_config_t config;
} kzg_commitments_context_t;

int kzg_commitments_init(kzg_commitments_context_t* ctx, const kzg_commitments_config_t* cfg);
int kzg_commitments_destroy(kzg_commitments_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* KZG_COMMITMENTS_TYPES_H */
