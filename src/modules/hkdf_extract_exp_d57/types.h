#ifndef HKDF_EXTRACT_EXP_D57_TYPES_H
#define HKDF_EXTRACT_EXP_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t prk;
    uint64_t okm;
} hkdf64_pair_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} hkdf_extract_exp_d57_meta_t;

#endif /* HKDF_EXTRACT_EXP_D57_TYPES_H */
