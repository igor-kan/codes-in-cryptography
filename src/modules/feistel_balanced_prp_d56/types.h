#ifndef FEISTEL_BALANCED_PRP_D56_TYPES_H
#define FEISTEL_BALANCED_PRP_D56_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t left;
    uint32_t right;
} feistel64_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} feistel_balanced_prp_d56_meta_t;

#endif /* FEISTEL_BALANCED_PRP_D56_TYPES_H */
