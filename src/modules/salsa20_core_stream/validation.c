#include "interface.h"
salsa20_core_stream_err_t salsa20_core_stream_validate(const uint8_t* key, const uint8_t* nonce) {
    return (key && nonce) ? SALSA20_CORE_STREAM_OK : SALSA20_CORE_STREAM_ERR_NULL;
}
