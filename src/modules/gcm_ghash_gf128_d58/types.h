#ifndef GCM_GHASH_GF128_D58_TYPES_H
#define GCM_GHASH_GF128_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t h_key;
    uint64_t digest;
} gf64_mac_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} gcm_ghash_gf128_d58_meta_t;

#endif /* GCM_GHASH_GF128_D58_TYPES_H */
