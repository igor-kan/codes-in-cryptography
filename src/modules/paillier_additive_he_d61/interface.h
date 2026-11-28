#ifndef PAILLIER_ADDITIVE_HE_D61_INTERFACE_H
#define PAILLIER_ADDITIVE_HE_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void paillier_keygen_d61(paillier_key_d61_t* k);
uint64_t paillier_encrypt_d61(uint64_t m, uint64_t r);
uint64_t paillier_decrypt_d61(uint64_t c);
bool paillier_additive_check_d61(uint64_t m1, uint64_t m2, uint64_t r1, uint64_t r2);

paillier_additive_he_d61_err_t paillier_additive_he_d61_validate_len(size_t n);
uint64_t paillier_additive_he_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t paillier_additive_he_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
paillier_additive_he_d61_err_t paillier_additive_he_d61_verify_guard(bool cond);

#endif /* PAILLIER_ADDITIVE_HE_D61_INTERFACE_H */
