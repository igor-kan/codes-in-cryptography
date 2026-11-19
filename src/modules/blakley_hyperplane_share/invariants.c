#include "interface.h"

blakley_hyperplane_share_err_t blakley_hyperplane_share_verify_guard(bool cond) {
    if (!cond) {
        return BLAKLEY_HYPERPLANE_SHARE_ERR_INVARIANT;
    }
    return BLAKLEY_HYPERPLANE_SHARE_OK;
}
