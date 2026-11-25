#include "interface.h"

pedersen_commit_d60_err_t pedersen_commit_d60_verify_guard(bool cond) {
    if (!cond) {
        return PEDERSEN_COMMIT_D60_ERR_INVARIANT;
    }
    return PEDERSEN_COMMIT_D60_OK;
}
