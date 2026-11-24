#include "interface.h"

feistel_8round_d59_err_t feistel_8round_d59_verify_guard(bool cond) {
    if (!cond) {
        return FEISTEL_8ROUND_D59_ERR_INVARIANT;
    }
    return FEISTEL_8ROUND_D59_OK;
}
