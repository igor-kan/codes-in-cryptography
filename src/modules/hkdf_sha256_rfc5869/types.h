#ifndef HKDF_SHA256_RFC5869_TYPES_H
#define HKDF_SHA256_RFC5869_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define HKDF_SHA256_DIGEST_LEN 32U
typedef struct {
    uint32_t state[8];
    uint64_t bitlen;
    uint8_t buf[64];
    size_t buf_len;
} hkdf_sha256_ctx_t;

#endif /* HKDF_SHA256_RFC5869_TYPES_H */
