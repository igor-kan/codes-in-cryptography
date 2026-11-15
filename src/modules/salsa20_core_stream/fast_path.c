#include "interface.h"
void salsa20_core_stream_xor_fast(const uint8_t key[32], const uint8_t nonce[8], const uint8_t* in, uint8_t* out, size_t len) {
    salsa20_core_stream_xor(key, nonce, 0, in, out, len);
}
