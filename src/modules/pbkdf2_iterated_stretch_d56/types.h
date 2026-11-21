#ifndef PBKDF2_ITERATED_STRETCH_D56_TYPES_H
#define PBKDF2_ITERATED_STRETCH_D56_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t derived_key;
    uint32_t rounds;
} kdf_output_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} pbkdf2_iterated_stretch_d56_meta_t;

#endif /* PBKDF2_ITERATED_STRETCH_D56_TYPES_H */
