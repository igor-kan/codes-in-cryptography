#include "interface.h"

poly1305_mac_step_d60_err_t poly1305_mac_step_d60_verify_guard(bool cond) {
    if (!cond) {
        return POLY1305_MAC_STEP_D60_ERR_INVARIANT;
    }
    return POLY1305_MAC_STEP_D60_OK;
}
