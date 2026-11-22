#include "interface.h"

poly1305_tag_mod2_d57_err_t poly1305_tag_mod2_d57_verify_guard(bool cond) {
    if (!cond) {
        return POLY1305_TAG_MOD2_D57_ERR_INVARIANT;
    }
    return POLY1305_TAG_MOD2_D57_OK;
}
