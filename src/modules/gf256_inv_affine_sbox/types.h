#ifndef GF256_INV_AFFINE_SBOX_TYPES_H
#define GF256_INV_AFFINE_SBOX_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t sbox[256];
} aes_sbox_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} gf256_inv_affine_sbox_meta_t;

#endif /* GF256_INV_AFFINE_SBOX_TYPES_H */
