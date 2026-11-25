#include "interface.h"

poly1305_mac_step_d60_err_t poly1305_mac_step_d60_validate_len(size_t n) {
    if (n == 0) {
        return POLY1305_MAC_STEP_D60_ERR_INVALID;
    }
    return POLY1305_MAC_STEP_D60_OK;
}
