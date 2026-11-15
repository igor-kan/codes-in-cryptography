#ifndef XTEA_CBC_MAC_INTERFACE_H
#define XTEA_CBC_MAC_INTERFACE_H

#include "types.h"
#include "errors.h"

void xtea_cbc_mac_encrypt_block(const xtea_key_t* key, uint32_t v[2]);
void xtea_cbc_mac_decrypt_block(const xtea_key_t* key, uint32_t v[2]);
xtea_cbc_mac_err_t xtea_cbc_mac_compute(const xtea_key_t* key, const uint8_t* msg, size_t blocks8, uint8_t tag[8]);
xtea_cbc_mac_err_t xtea_cbc_mac_validate(const xtea_key_t* key, size_t len);
void xtea_cbc_mac_encrypt_fast(const xtea_key_t* key, const uint32_t* in, uint32_t* out, size_t blocks);
xtea_cbc_mac_err_t xtea_cbc_mac_batch_verify(const xtea_key_t* key, const uint32_t* blocks, size_t n);
xtea_cbc_mac_err_t xtea_cbc_mac_check_bijection(const xtea_key_t* key, uint32_t v0, uint32_t v1);

#endif /* XTEA_CBC_MAC_INTERFACE_H */
