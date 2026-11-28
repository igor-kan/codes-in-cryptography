#ifndef MERKLE_HELLMAN_KNAPSACK_D61_INTERFACE_H
#define MERKLE_HELLMAN_KNAPSACK_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void mh_public_key_d61(mh_key_d61_t* k);
uint64_t mh_encrypt_d61(const mh_key_d61_t* k, uint8_t msg);
uint8_t mh_decrypt_d61(const mh_key_d61_t* k, uint64_t ct);

merkle_hellman_knapsack_d61_err_t merkle_hellman_knapsack_d61_validate_len(size_t n);
uint64_t merkle_hellman_knapsack_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t merkle_hellman_knapsack_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
merkle_hellman_knapsack_d61_err_t merkle_hellman_knapsack_d61_verify_guard(bool cond);

#endif /* MERKLE_HELLMAN_KNAPSACK_D61_INTERFACE_H */
