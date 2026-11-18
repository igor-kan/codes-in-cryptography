#include "interface.h"

gimli_24round_spbox_perm_err_t gimli_24round_spbox_perm_verify_guard(bool cond) {
    if (!cond) {
        return GIMLI_24ROUND_SPBOX_PERM_ERR_INVARIANT;
    }
    return GIMLI_24ROUND_SPBOX_PERM_OK;
}
