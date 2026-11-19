#ifndef RC4_DROP3072_STREAM_C11_TYPES_H
#define RC4_DROP3072_STREAM_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t S[256];
    uint8_t i;
    uint8_t j;
} rc4_state_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} rc4_drop3072_stream_c11_meta_t;

#endif /* RC4_DROP3072_STREAM_C11_TYPES_H */
