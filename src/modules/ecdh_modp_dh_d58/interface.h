#ifndef ECDH_MODP_DH_D58_INTERFACE_H
#define ECDH_MODP_DH_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t dh_pow_mod(uint64_t g, uint64_t exp, uint64_t p);

ecdh_modp_dh_d58_err_t ecdh_modp_dh_d58_validate_len(size_t n);
uint64_t ecdh_modp_dh_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t ecdh_modp_dh_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
ecdh_modp_dh_d58_err_t ecdh_modp_dh_d58_verify_guard(bool cond);

#endif /* ECDH_MODP_DH_D58_INTERFACE_H */
