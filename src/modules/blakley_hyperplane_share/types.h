#ifndef BLAKLEY_HYPERPLANE_SHARE_TYPES_H
#define BLAKLEY_HYPERPLANE_SHARE_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BLAK_P 2147483647ULL
typedef struct {
    uint64_t a;
    uint64_t b;
    uint64_t c;
} hyperplane_share_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} blakley_hyperplane_share_meta_t;

#endif /* BLAKLEY_HYPERPLANE_SHARE_TYPES_H */
