#ifndef XTEA_FEISTEL_BLOCK_D56_TYPES_H
#define XTEA_FEISTEL_BLOCK_D56_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t words[4];
} xtea_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} xtea_feistel_block_d56_meta_t;

#endif /* XTEA_FEISTEL_BLOCK_D56_TYPES_H */
