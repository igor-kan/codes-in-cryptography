#ifndef PBKDF2_HMAC_KDF_TYPES_H
#define PBKDF2_HMAC_KDF_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define PBKDF2_SHA256_HLEN 32U
typedef struct {
    uint32_t iterations;
    size_t dk_len;
} pbkdf2_params_t;

#endif /* PBKDF2_HMAC_KDF_TYPES_H */
