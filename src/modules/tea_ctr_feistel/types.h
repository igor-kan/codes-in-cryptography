#ifndef TEA_CTR_FEISTEL_TYPES_H
#define TEA_CTR_FEISTEL_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t k[4];
} tea_key_t;

#endif /* TEA_CTR_FEISTEL_TYPES_H */
