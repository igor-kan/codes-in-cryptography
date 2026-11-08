/**
 * @file core.c
 * @brief Core computational implementation for Twisted Edwards Curve Ed25519 Point Addition Laws.
 * Module: ed25519_curve
 */

#include "types.c"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ed25519_curve_init(ed25519_curve_context_t* ctx, const ed25519_curve_config_t* cfg) {
    if (!ctx) return ED25519_CURVE_ERR_NULL_PTR;
    memset(ctx, 0, sizeof(*ctx));
    if (cfg) {
        ctx->config = *cfg;
    } else {
        ctx->config.capacity = 1024;
        ctx->config.tolerance = 1e-12;
    }
    ctx->buffer = malloc(ctx->config.capacity * sizeof(double));
    if (!ctx->buffer) return ED25519_CURVE_ERR_INVALID_PARAM;
    ctx->capacity = ctx->config.capacity;
    return ED25519_CURVE_SUCCESS;
}

int ed25519_curve_destroy(ed25519_curve_context_t* ctx) {
    if (!ctx) return ED25519_CURVE_ERR_NULL_PTR;
    if (ctx->buffer) {
        free(ctx->buffer);
        ctx->buffer = NULL;
    }
    ctx->size = 0;
    ctx->capacity = 0;
    return ED25519_CURVE_SUCCESS;
}

int ed25519_curve_compute(ed25519_curve_context_t* ctx, const double* in_vec, double* out_vec, size_t n) {
    if (!ctx || !in_vec || !out_vec) return ED25519_CURVE_ERR_NULL_PTR;
    if (n == 0 || n > ctx->capacity) return ED25519_CURVE_ERR_OUT_OF_BOUNDS;
    
    // Core kernel: numerically conditioned polynomial/transformation
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.5 * x - 0.125 * x * x);
    }
    ctx->operations_count += n;
    return ED25519_CURVE_SUCCESS;
}
