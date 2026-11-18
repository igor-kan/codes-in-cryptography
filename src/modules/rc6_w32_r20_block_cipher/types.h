#ifndef RC6_W32_R20_BLOCK_CIPHER_TYPES_H
#define RC6_W32_R20_BLOCK_CIPHER_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t S[44];
} rc6_ctx_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} rc6_w32_r20_block_cipher_meta_t;

#endif /* RC6_W32_R20_BLOCK_CIPHER_TYPES_H */
