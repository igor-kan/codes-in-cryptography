#include "interface.h"

trivium_lfsr_stream_d61_err_t trivium_lfsr_stream_d61_validate_len(size_t n) {
    if (n == 0) {
        return TRIVIUM_LFSR_STREAM_D61_ERR_INVALID;
    }
    return TRIVIUM_LFSR_STREAM_D61_OK;
}
