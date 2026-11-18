#ifndef POLY1305_R_CLAMPING_TAG_TYPES_H
#define POLY1305_R_CLAMPING_TAG_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t r_lo;
    uint64_t r_hi;
    uint64_t s_lo;
    uint64_t s_hi;
} poly1305_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} poly1305_r_clamping_tag_meta_t;

#endif /* POLY1305_R_CLAMPING_TAG_TYPES_H */
