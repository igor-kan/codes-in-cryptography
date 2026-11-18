#ifndef POLY1305_R_CLAMPING_TAG_INTERFACE_H
#define POLY1305_R_CLAMPING_TAG_INTERFACE_H

#include "types.h"
#include "errors.h"

void poly1305_clamp_key(const uint8_t raw[32], poly1305_key_t* out);
uint64_t poly1305_short_tag64(const poly1305_key_t* k, const uint64_t* blocks, size_t n);

poly1305_r_clamping_tag_err_t poly1305_r_clamping_tag_validate_len(size_t n);
uint64_t poly1305_r_clamping_tag_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t poly1305_r_clamping_tag_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
poly1305_r_clamping_tag_err_t poly1305_r_clamping_tag_verify_guard(bool cond);

#endif /* POLY1305_R_CLAMPING_TAG_INTERFACE_H */
