#include "interface.h"

poly1305_tag_mod2_d57_err_t poly1305_tag_mod2_d57_validate_len(size_t n) {
    if (n == 0) {
        return POLY1305_TAG_MOD2_D57_ERR_INVALID;
    }
    return POLY1305_TAG_MOD2_D57_OK;
}
