#include "interface.h"

xtea_feistel_block_d56_err_t xtea_feistel_block_d56_verify_guard(bool cond) {
    if (!cond) {
        return XTEA_FEISTEL_BLOCK_D56_ERR_INVARIANT;
    }
    return XTEA_FEISTEL_BLOCK_D56_OK;
}
