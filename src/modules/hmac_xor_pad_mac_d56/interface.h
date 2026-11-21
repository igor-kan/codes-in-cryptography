#ifndef HMAC_XOR_PAD_MAC_D56_INTERFACE_H
#define HMAC_XOR_PAD_MAC_D56_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t nested_hmac64(const uint8_t *key, size_t klen, const uint8_t *msg, size_t mlen);
int verify_hmac64(uint64_t a, uint64_t b);

hmac_xor_pad_mac_d56_err_t hmac_xor_pad_mac_d56_validate_len(size_t n);
uint64_t hmac_xor_pad_mac_d56_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t hmac_xor_pad_mac_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
hmac_xor_pad_mac_d56_err_t hmac_xor_pad_mac_d56_verify_guard(bool cond);

#endif /* HMAC_XOR_PAD_MAC_D56_INTERFACE_H */
