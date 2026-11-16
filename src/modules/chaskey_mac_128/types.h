#ifndef CHASKEY_MAC_128_TYPES_H
#define CHASKEY_MAC_128_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t k[4];
    uint32_t k1[4];
    uint32_t k2[4];
} chaskey_ctx_t;

#endif /* CHASKEY_MAC_128_TYPES_H */
