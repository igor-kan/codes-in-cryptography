#include "interface.h"

rc4_drop3072_stream_c11_err_t rc4_drop3072_stream_c11_verify_guard(bool cond) {
    if (!cond) {
        return RC4_DROP3072_STREAM_C11_ERR_INVARIANT;
    }
    return RC4_DROP3072_STREAM_C11_OK;
}
