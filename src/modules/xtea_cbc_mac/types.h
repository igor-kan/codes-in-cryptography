#ifndef XTEA_CBC_MAC_TYPES_H
#define XTEA_CBC_MAC_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define XTEA_ROUNDS 32U
#define XTEA_DELTA 0x9E3779B9U
typedef struct {
    uint32_t k[4];
} xtea_key_t;

#endif /* XTEA_CBC_MAC_TYPES_H */
