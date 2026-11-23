#ifndef CBC_MAC_XOR_D58_TYPES_H
#define CBC_MAC_XOR_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t key;
    uint64_t tag;
} cbc_tag_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} cbc_mac_xor_d58_meta_t;

#endif /* CBC_MAC_XOR_D58_TYPES_H */
