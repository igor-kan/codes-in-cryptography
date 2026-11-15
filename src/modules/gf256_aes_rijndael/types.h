#ifndef GF256_AES_RIJNDAEL_TYPES_H
#define GF256_AES_RIJNDAEL_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define AES_POLY 0x1BU
typedef struct {
    uint8_t col[4];
} gf256_col_t;

#endif /* GF256_AES_RIJNDAEL_TYPES_H */
