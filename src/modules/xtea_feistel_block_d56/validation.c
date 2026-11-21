#include "interface.h"

xtea_feistel_block_d56_err_t xtea_feistel_block_d56_validate_len(size_t n) {
    if (n == 0) {
        return XTEA_FEISTEL_BLOCK_D56_ERR_INVALID;
    }
    return XTEA_FEISTEL_BLOCK_D56_OK;
}
