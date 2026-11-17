#ifndef SCRYPT_SALSA20_ROMIX_TYPES_H
#define SCRYPT_SALSA20_ROMIX_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t words[16];
} salsa8_block_t;

#endif /* SCRYPT_SALSA20_ROMIX_TYPES_H */
