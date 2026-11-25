#ifndef GF128_GHASH_MUL_D60_TYPES_H
#define GF128_GHASH_MUL_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t hi;
    uint64_t lo;
} gf128_elem_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} gf128_ghash_mul_d60_meta_t;

#endif /* GF128_GHASH_MUL_D60_TYPES_H */
