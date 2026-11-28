#ifndef THREEFISH256_ARX_D61_TYPES_H
#define THREEFISH256_ARX_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TF256_ROUNDS 72
typedef struct {
    uint64_t key[4];
    uint64_t tweak[2];
} threefish256_ctx_d61_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} threefish256_arx_d61_meta_t;

#endif /* THREEFISH256_ARX_D61_TYPES_H */
