#ifndef RC4_DROP_STREAM_D57_TYPES_H
#define RC4_DROP_STREAM_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t s[256];
    uint8_t i;
    uint8_t j;
} rc4_ctx_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} rc4_drop_stream_d57_meta_t;

#endif /* RC4_DROP_STREAM_D57_TYPES_H */
