#ifndef SOLOVAY_STRASSEN_JACOBI_TYPES_H
#define SOLOVAY_STRASSEN_JACOBI_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int jacobi;
    bool euler_pass;
} ss_witness_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} solovay_strassen_jacobi_meta_t;

#endif /* SOLOVAY_STRASSEN_JACOBI_TYPES_H */
