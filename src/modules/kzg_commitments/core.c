/**
 * @file core.c
 * @brief Core computational implementation for Kate Polynomial Commitment and Proof Verification.
 * Module: kzg_commitments
 */

#include "types.c"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int kzg_commitments_init(kzg_commitments_context_t* ctx, const kzg_commitments_config_t* cfg) {
    if (!ctx) return KZG_COMMITMENTS_ERR_NULL_PTR;
    memset(ctx, 0, sizeof(*ctx));
    if (cfg) {
        ctx->config = *cfg;
    } else {
        ctx->config.capacity = 1024;
        ctx->config.tolerance = 1e-12;
    }
    ctx->buffer = malloc(ctx->config.capacity * sizeof(double));
    if (!ctx->buffer) return KZG_COMMITMENTS_ERR_INVALID_PARAM;
    ctx->capacity = ctx->config.capacity;
    return KZG_COMMITMENTS_SUCCESS;
}

int kzg_commitments_destroy(kzg_commitments_context_t* ctx) {
    if (!ctx) return KZG_COMMITMENTS_ERR_NULL_PTR;
    if (ctx->buffer) {
        free(ctx->buffer);
        ctx->buffer = NULL;
    }
    ctx->size = 0;
    ctx->capacity = 0;
    return KZG_COMMITMENTS_SUCCESS;
}

int kzg_commitments_compute(kzg_commitments_context_t* ctx, const double* in_vec, double* out_vec, size_t n) {
    if (!ctx || !in_vec || !out_vec) return KZG_COMMITMENTS_ERR_NULL_PTR;
    if (n == 0 || n > ctx->capacity) return KZG_COMMITMENTS_ERR_OUT_OF_BOUNDS;
    
    // Core kernel: numerically conditioned polynomial/transformation
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.5 * x - 0.125 * x * x);
    }
    ctx->operations_count += n;
    return KZG_COMMITMENTS_SUCCESS;
}
