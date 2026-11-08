/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Keccak-f[1600] Cryptographic Sponge Permutation.
 * Module: sha3_sponge
 */

#ifndef SHA3_SPONGE_TYPES_H
#define SHA3_SPONGE_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SHA3_SPONGE_ALIGNMENT 64
#define SHA3_SPONGE_SUCCESS 0
#define SHA3_SPONGE_ERR_NULL_PTR -1
#define SHA3_SPONGE_ERR_INVALID_PARAM -2
#define SHA3_SPONGE_ERR_OUT_OF_BOUNDS -3

typedef struct sha3_sponge_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} sha3_sponge_config_t;

typedef struct sha3_sponge_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    sha3_sponge_config_t config;
} sha3_sponge_context_t;

int sha3_sponge_init(sha3_sponge_context_t* ctx, const sha3_sponge_config_t* cfg);
int sha3_sponge_destroy(sha3_sponge_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* SHA3_SPONGE_TYPES_H */
