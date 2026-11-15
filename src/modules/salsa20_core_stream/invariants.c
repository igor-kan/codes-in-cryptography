#include "interface.h"
#include <stdlib.h>
#include <string.h>

salsa20_core_stream_err_t salsa20_core_stream_check_involution(const uint8_t key[32], const uint8_t nonce[8], const uint8_t* msg, size_t len) {
    uint8_t* ct = (uint8_t*)malloc(len + 1);
    uint8_t* pt = (uint8_t*)malloc(len + 1);
    if (!ct || !pt) { free(ct); free(pt); return SALSA20_CORE_STREAM_ERR_BOUNDS; }
    salsa20_core_stream_xor(key, nonce, 0, msg, ct, len);
    salsa20_core_stream_xor(key, nonce, 0, ct, pt, len);
    int ok = (len == 0) || (memcmp(msg, pt, len) == 0);
    free(ct); free(pt);
    return ok ? SALSA20_CORE_STREAM_OK : SALSA20_CORE_STREAM_ERR_INVARIANT;
}
