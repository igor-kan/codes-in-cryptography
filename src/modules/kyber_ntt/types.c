/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Number Theoretic Transform for ML-KEM Polynomial Arithmetic.
 * Module: kyber_ntt
 */

#ifndef KYBER_NTT_TYPES_H
#define KYBER_NTT_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define KYBER_NTT_ALIGNMENT 64
#define KYBER_NTT_SUCCESS 0
#define KYBER_NTT_ERR_NULL_PTR -1
#define KYBER_NTT_ERR_INVALID_PARAM -2
#define KYBER_NTT_ERR_OUT_OF_BOUNDS -3

typedef struct kyber_ntt_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} kyber_ntt_config_t;

typedef struct kyber_ntt_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    kyber_ntt_config_t config;
} kyber_ntt_context_t;

int kyber_ntt_init(kyber_ntt_context_t* ctx, const kyber_ntt_config_t* cfg);
int kyber_ntt_destroy(kyber_ntt_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* KYBER_NTT_TYPES_H */
