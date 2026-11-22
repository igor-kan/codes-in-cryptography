#include "interface.h"

rc4_drop_stream_d57_err_t rc4_drop_stream_d57_verify_guard(bool cond) {
    if (!cond) {
        return RC4_DROP_STREAM_D57_ERR_INVARIANT;
    }
    return RC4_DROP_STREAM_D57_OK;
}
