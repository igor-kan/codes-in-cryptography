#ifndef TEA_CLASSIC_64_D58_TYPES_H
#define TEA_CLASSIC_64_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t words[4];
} tea_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} tea_classic_64_d58_meta_t;

#endif /* TEA_CLASSIC_64_D58_TYPES_H */
