#ifndef SALSA20_QR_CORE_D59_INTERFACE_H
#define SALSA20_QR_CORE_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

void salsa_qr(uint32_t *y0, uint32_t *y1, uint32_t *y2, uint32_t *y3);
void salsa20_core(const uint32_t in[16], uint32_t out[16]);

salsa20_qr_core_d59_err_t salsa20_qr_core_d59_validate_len(size_t n);
uint64_t salsa20_qr_core_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t salsa20_qr_core_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
salsa20_qr_core_d59_err_t salsa20_qr_core_d59_verify_guard(bool cond);

#endif /* SALSA20_QR_CORE_D59_INTERFACE_H */
