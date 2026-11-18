#include "interface.h"

gimli_24round_spbox_perm_err_t gimli_24round_spbox_perm_validate_len(size_t n) {
    if (n == 0) {
        return GIMLI_24ROUND_SPBOX_PERM_ERR_INVALID;
    }
    return GIMLI_24ROUND_SPBOX_PERM_OK;
}
