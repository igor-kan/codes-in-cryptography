#include "interface.h"

rc4_drop3072_stream_c11_err_t rc4_drop3072_stream_c11_validate_len(size_t n) {
    if (n == 0) {
        return RC4_DROP3072_STREAM_C11_ERR_INVALID;
    }
    return RC4_DROP3072_STREAM_C11_OK;
}
