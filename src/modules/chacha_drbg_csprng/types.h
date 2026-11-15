#ifndef CHACHA_DRBG_CSPRNG_TYPES_H
#define CHACHA_DRBG_CSPRNG_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t key[32];
    uint64_t counter;
} chacha_drbg_t;

#endif /* CHACHA_DRBG_CSPRNG_TYPES_H */
