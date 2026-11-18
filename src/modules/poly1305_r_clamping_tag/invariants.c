#include "interface.h"

poly1305_r_clamping_tag_err_t poly1305_r_clamping_tag_verify_guard(bool cond) {
    if (!cond) {
        return POLY1305_R_CLAMPING_TAG_ERR_INVARIANT;
    }
    return POLY1305_R_CLAMPING_TAG_OK;
}
