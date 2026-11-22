#ifndef SPECK64_128_ARX_D57_TYPES_H
#define SPECK64_128_ARX_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t rk[27];
} speck64_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} speck64_128_arx_d57_meta_t;

#endif /* SPECK64_128_ARX_D57_TYPES_H */
