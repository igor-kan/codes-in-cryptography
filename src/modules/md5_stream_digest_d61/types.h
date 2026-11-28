#ifndef MD5_STREAM_DIGEST_D61_TYPES_H
#define MD5_STREAM_DIGEST_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MD5_BLOCK_BYTES 64U
typedef struct {
    uint32_t state[4];
    uint64_t total_len;
    uint8_t buffer[MD5_BLOCK_BYTES];
    size_t buffered;
} md5_ctx_d61_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} md5_stream_digest_d61_meta_t;

#endif /* MD5_STREAM_DIGEST_D61_TYPES_H */
