#ifndef FEISTEL_8ROUND_D59_TYPES_H
#define FEISTEL_8ROUND_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t block;
    uint32_t rk[8];
} feistel8_ctx_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} feistel_8round_d59_meta_t;

#endif /* FEISTEL_8ROUND_D59_TYPES_H */
