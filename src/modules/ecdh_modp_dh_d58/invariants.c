#include "interface.h"

ecdh_modp_dh_d58_err_t ecdh_modp_dh_d58_verify_guard(bool cond) {
    if (!cond) {
        return ECDH_MODP_DH_D58_ERR_INVARIANT;
    }
    return ECDH_MODP_DH_D58_OK;
}
