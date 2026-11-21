#ifndef GF256_AES_MUL_INV_D56_TYPES_H
#define GF256_AES_MUL_INV_D56_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t lhs;
    uint8_t rhs;
    uint8_t prod;
} gf256_pair_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} gf256_aes_mul_inv_d56_meta_t;

#endif /* GF256_AES_MUL_INV_D56_TYPES_H */
