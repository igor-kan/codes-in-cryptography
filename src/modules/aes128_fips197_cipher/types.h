#ifndef AES128_FIPS197_CIPHER_TYPES_H
#define AES128_FIPS197_CIPHER_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t rk[176];
} aes128_ctx_t;

#endif /* AES128_FIPS197_CIPHER_TYPES_H */
