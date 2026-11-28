#ifndef RC5_32_12_16_D61_TYPES_H
#define RC5_32_12_16_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RC5_ROUNDS 12
#define RC5_SUBKEYS (2 * (RC5_ROUNDS + 1))
typedef struct {
    uint32_t s[RC5_SUBKEYS];
} rc5_ctx_d61_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} rc5_32_12_16_d61_meta_t;

#endif /* RC5_32_12_16_D61_TYPES_H */
