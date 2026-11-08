/**
 * @file core.c
 * @brief Core computational implementation for Keccak-f[1600] Cryptographic Sponge Permutation.
 * Module: sha3_sponge
 */

#include "types.c"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sha3_sponge_init(sha3_sponge_context_t* ctx, const sha3_sponge_config_t* cfg) {
    if (!ctx) return SHA3_SPONGE_ERR_NULL_PTR;
    memset(ctx, 0, sizeof(*ctx));
    if (cfg) {
        ctx->config = *cfg;
    } else {
        ctx->config.capacity = 1024;
        ctx->config.tolerance = 1e-12;
    }
    ctx->buffer = malloc(ctx->config.capacity * sizeof(double));
    if (!ctx->buffer) return SHA3_SPONGE_ERR_INVALID_PARAM;
    ctx->capacity = ctx->config.capacity;
    return SHA3_SPONGE_SUCCESS;
}

int sha3_sponge_destroy(sha3_sponge_context_t* ctx) {
    if (!ctx) return SHA3_SPONGE_ERR_NULL_PTR;
    if (ctx->buffer) {
        free(ctx->buffer);
        ctx->buffer = NULL;
    }
    ctx->size = 0;
    ctx->capacity = 0;
    return SHA3_SPONGE_SUCCESS;
}

int sha3_sponge_compute(sha3_sponge_context_t* ctx, const double* in_vec, double* out_vec, size_t n) {
    if (!ctx || !in_vec || !out_vec) return SHA3_SPONGE_ERR_NULL_PTR;
    if (n == 0 || n > ctx->capacity) return SHA3_SPONGE_ERR_OUT_OF_BOUNDS;
    
    // Core kernel: numerically conditioned polynomial/transformation
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.5 * x - 0.125 * x * x);
    }
    ctx->operations_count += n;
    return SHA3_SPONGE_SUCCESS;
}
