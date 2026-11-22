#ifndef POLY1305_TAG_MOD2_D57_TYPES_H
#define POLY1305_TAG_MOD2_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t r;
    uint64_t s;
} cw_mac_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} poly1305_tag_mod2_d57_meta_t;

#endif /* POLY1305_TAG_MOD2_D57_TYPES_H */
