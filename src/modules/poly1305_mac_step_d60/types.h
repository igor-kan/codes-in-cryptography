#ifndef POLY1305_MAC_STEP_D60_TYPES_H
#define POLY1305_MAC_STEP_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t r[5];
    uint32_t h[5];
    uint32_t pad[4];
} poly1305_state_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} poly1305_mac_step_d60_meta_t;

#endif /* POLY1305_MAC_STEP_D60_TYPES_H */
