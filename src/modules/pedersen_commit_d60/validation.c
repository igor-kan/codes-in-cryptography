#include "interface.h"

pedersen_commit_d60_err_t pedersen_commit_d60_validate_len(size_t n) {
    if (n == 0) {
        return PEDERSEN_COMMIT_D60_ERR_INVALID;
    }
    return PEDERSEN_COMMIT_D60_OK;
}
