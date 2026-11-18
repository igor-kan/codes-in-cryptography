#ifndef GIMLI_24ROUND_SPBOX_PERM_TYPES_H
#define GIMLI_24ROUND_SPBOX_PERM_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t s[12];
} gimli_state_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} gimli_24round_spbox_perm_meta_t;

#endif /* GIMLI_24ROUND_SPBOX_PERM_TYPES_H */
