#ifndef RABIN_WILLIAMS_SQRT_TRAP_INTERFACE_H
#define RABIN_WILLIAMS_SQRT_TRAP_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t rabin_encrypt(const rabin_key_t* k, uint64_t m);
void rabin_decrypt_roots(const rabin_key_t* k, uint64_t c, uint64_t roots[4]);

rabin_williams_sqrt_trap_err_t rabin_williams_sqrt_trap_validate_len(size_t n);
uint64_t rabin_williams_sqrt_trap_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t rabin_williams_sqrt_trap_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
rabin_williams_sqrt_trap_err_t rabin_williams_sqrt_trap_verify_guard(bool cond);

#endif /* RABIN_WILLIAMS_SQRT_TRAP_INTERFACE_H */
