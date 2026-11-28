#include "interface.h"

trivium_lfsr_stream_d61_err_t trivium_lfsr_stream_d61_verify_guard(bool cond) {
    if (!cond) {
        return TRIVIUM_LFSR_STREAM_D61_ERR_INVARIANT;
    }
    return TRIVIUM_LFSR_STREAM_D61_OK;
}
