#ifndef POLY1305_MAC_STEP_D60_INTERFACE_H
#define POLY1305_MAC_STEP_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

void poly1305_init_d60(poly1305_state_t* st, const uint8_t key[32]);
void poly1305_block_d60(poly1305_state_t* st, const uint8_t blk[16]);
void poly1305_finish_d60(poly1305_state_t* st, uint8_t mac[16]);

poly1305_mac_step_d60_err_t poly1305_mac_step_d60_validate_len(size_t n);
uint64_t poly1305_mac_step_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t poly1305_mac_step_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
poly1305_mac_step_d60_err_t poly1305_mac_step_d60_verify_guard(bool cond);

#endif /* POLY1305_MAC_STEP_D60_INTERFACE_H */
