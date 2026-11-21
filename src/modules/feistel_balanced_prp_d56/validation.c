#include "interface.h"

feistel_balanced_prp_d56_err_t feistel_balanced_prp_d56_validate_len(size_t n) {
    if (n == 0) {
        return FEISTEL_BALANCED_PRP_D56_ERR_INVALID;
    }
    return FEISTEL_BALANCED_PRP_D56_OK;
}
