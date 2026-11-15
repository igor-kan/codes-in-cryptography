#include "interface.h"
salsa20_core_stream_err_t salsa20_core_stream_batch_xor(const uint8_t key[32], const uint8_t nonce[8], uint8_t* buf, size_t len) {
    return salsa20_core_stream_xor(key, nonce, 0, buf, buf, len);
}
