#ifndef RIPEMD160_DIGEST_D61_TYPES_H
#define RIPEMD160_DIGEST_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RMD_BLOCK_BYTES 64U
typedef struct {
    uint32_t state[5];
    uint64_t total_len;
    uint8_t buffer[RMD_BLOCK_BYTES];
    size_t buffered;
} ripemd160_ctx_d61_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} ripemd160_digest_d61_meta_t;

#endif /* RIPEMD160_DIGEST_D61_TYPES_H */
