#ifndef TRIVIUM_LFSR_STREAM_D61_TYPES_H
#define TRIVIUM_LFSR_STREAM_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TRIVIUM_STATE_BITS 288
typedef struct {
    uint8_t bits[TRIVIUM_STATE_BITS];
} trivium_state_d61_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} trivium_lfsr_stream_d61_meta_t;

#endif /* TRIVIUM_LFSR_STREAM_D61_TYPES_H */
