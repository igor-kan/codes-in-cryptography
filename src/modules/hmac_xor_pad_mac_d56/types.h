#ifndef HMAC_XOR_PAD_MAC_D56_TYPES_H
#define HMAC_XOR_PAD_MAC_D56_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t tag_lo;
    uint64_t tag_hi;
} mac_tag_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} hmac_xor_pad_mac_d56_meta_t;

#endif /* HMAC_XOR_PAD_MAC_D56_TYPES_H */
