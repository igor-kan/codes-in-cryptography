#include "interface.h"

feistel_balanced_prp_d56_err_t feistel_balanced_prp_d56_verify_guard(bool cond) {
    if (!cond) {
        return FEISTEL_BALANCED_PRP_D56_ERR_INVARIANT;
    }
    return FEISTEL_BALANCED_PRP_D56_OK;
}
