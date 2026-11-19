#include "interface.h"

blakley_hyperplane_share_err_t blakley_hyperplane_share_validate_len(size_t n) {
    if (n == 0) {
        return BLAKLEY_HYPERPLANE_SHARE_ERR_INVALID;
    }
    return BLAKLEY_HYPERPLANE_SHARE_OK;
}
