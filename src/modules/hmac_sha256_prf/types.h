#ifndef HMAC_SHA256_PRF_TYPES_H
#define HMAC_SHA256_PRF_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define HMAC_SHA256_DIGEST_LEN 32U
#define HMAC_SHA256_BLOCK_LEN 64U
typedef struct {
    uint8_t bytes[32];
} hmac_tag_t;

#endif /* HMAC_SHA256_PRF_TYPES_H */
