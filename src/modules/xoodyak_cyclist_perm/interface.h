#ifndef XOODYAK_CYCLIST_PERM_INTERFACE_H
#define XOODYAK_CYCLIST_PERM_INTERFACE_H

#include "types.h"
#include "errors.h"

void xoodoo_permute_12(xoodoo_state_t* st);
xoodyak_cyclist_perm_err_t xoodyak_duplex_tag(const uint8_t* key, size_t key_len, const uint8_t* msg, size_t msg_len, uint8_t out_tag[16]);
xoodyak_cyclist_perm_err_t xoodyak_validate_key(const uint8_t* key, size_t key_len);
void xoodoo_fast_xor_in(xoodoo_state_t* st, const uint8_t* block, size_t len);
void xoodyak_parallel_macs(const uint8_t key[16], const uint8_t* msgs, size_t stride, size_t count, uint8_t* out_tags);
xoodyak_cyclist_perm_err_t xoodoo_verify_avalanche(void);

#endif /* XOODYAK_CYCLIST_PERM_INTERFACE_H */
