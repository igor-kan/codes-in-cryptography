#ifndef FLETCHER64_ADLER32_DUAL_TYPES_H
#define FLETCHER64_ADLER32_DUAL_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t adler32;
    uint64_t fletcher64;
} dual_csum_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} fletcher64_adler32_dual_meta_t;

#endif /* FLETCHER64_ADLER32_DUAL_TYPES_H */
