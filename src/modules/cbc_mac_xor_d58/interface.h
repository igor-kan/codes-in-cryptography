#ifndef CBC_MAC_XOR_D58_INTERFACE_H
#define CBC_MAC_XOR_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t cbc_mac64(uint64_t key, const uint64_t *blocks, size_t n);

cbc_mac_xor_d58_err_t cbc_mac_xor_d58_validate_len(size_t n);
uint64_t cbc_mac_xor_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t cbc_mac_xor_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
cbc_mac_xor_d58_err_t cbc_mac_xor_d58_verify_guard(bool cond);

#endif /* CBC_MAC_XOR_D58_INTERFACE_H */
