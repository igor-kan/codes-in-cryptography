#include "interface.h"

poly1305_r_clamping_tag_err_t poly1305_r_clamping_tag_validate_len(size_t n) {
    if (n == 0) {
        return POLY1305_R_CLAMPING_TAG_ERR_INVALID;
    }
    return POLY1305_R_CLAMPING_TAG_OK;
}
