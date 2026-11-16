#ifndef CHASKEY_MAC_128_INTERFACE_H
#define CHASKEY_MAC_128_INTERFACE_H

#include "types.h"
#include "errors.h"

void chaskey_init(chaskey_ctx_t* ctx, const uint8_t key[16]);
void chaskey_mac(const chaskey_ctx_t* ctx, const uint8_t* msg, size_t len, uint8_t tag[16]);
chaskey_mac_128_err_t chaskey_validate(const chaskey_ctx_t* ctx, const uint8_t tag[16]);
int chaskey_verify_ct(const chaskey_ctx_t* ctx, const uint8_t* msg, size_t len, const uint8_t expected[16]);
chaskey_mac_128_err_t chaskey_batch_verify_mt(const chaskey_ctx_t* ctx, const uint8_t** msgs, const size_t* lens, const uint8_t* tags, size_t count, size_t num_threads);
chaskey_mac_128_err_t chaskey_verify_invariants(const uint8_t key[16], const uint8_t* msg, size_t len);

#endif /* CHASKEY_MAC_128_INTERFACE_H */
