#ifndef SALSA20_CORE_STREAM_INTERFACE_H
#define SALSA20_CORE_STREAM_INTERFACE_H

#include "types.h"
#include "errors.h"

void salsa20_core_stream_block(uint32_t out[16], const uint32_t in[16]);
salsa20_core_stream_err_t salsa20_core_stream_xor(const uint8_t key[32], const uint8_t nonce[8], uint64_t ctr, const uint8_t* in, uint8_t* out, size_t len);
salsa20_core_stream_err_t salsa20_core_stream_validate(const uint8_t* key, const uint8_t* nonce);
void salsa20_core_stream_xor_fast(const uint8_t key[32], const uint8_t nonce[8], const uint8_t* in, uint8_t* out, size_t len);
salsa20_core_stream_err_t salsa20_core_stream_batch_xor(const uint8_t key[32], const uint8_t nonce[8], uint8_t* buf, size_t len);
salsa20_core_stream_err_t salsa20_core_stream_check_involution(const uint8_t key[32], const uint8_t nonce[8], const uint8_t* msg, size_t len);

#endif /* SALSA20_CORE_STREAM_INTERFACE_H */
