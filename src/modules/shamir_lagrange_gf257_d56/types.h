#ifndef SHAMIR_LAGRANGE_GF257_D56_TYPES_H
#define SHAMIR_LAGRANGE_GF257_D56_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int x;
    int y;
} gf257_share_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} shamir_lagrange_gf257_d56_meta_t;

#endif /* SHAMIR_LAGRANGE_GF257_D56_TYPES_H */
