#ifndef POLY1305_TAG_MOD2_D57_INTERFACE_H
#define POLY1305_TAG_MOD2_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t cw61_mac(uint64_t r, uint64_t s, const uint64_t *blocks, size_t n);

poly1305_tag_mod2_d57_err_t poly1305_tag_mod2_d57_validate_len(size_t n);
uint64_t poly1305_tag_mod2_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t poly1305_tag_mod2_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
poly1305_tag_mod2_d57_err_t poly1305_tag_mod2_d57_verify_guard(bool cond);

#endif /* POLY1305_TAG_MOD2_D57_INTERFACE_H */
