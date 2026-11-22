#include "interface.h"

rc4_drop_stream_d57_err_t rc4_drop_stream_d57_validate_len(size_t n) {
    if (n == 0) {
        return RC4_DROP_STREAM_D57_ERR_INVALID;
    }
    return RC4_DROP_STREAM_D57_OK;
}
