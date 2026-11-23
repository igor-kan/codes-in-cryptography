#include "interface.h"

ecdh_modp_dh_d58_err_t ecdh_modp_dh_d58_validate_len(size_t n) {
    if (n == 0) {
        return ECDH_MODP_DH_D58_ERR_INVALID;
    }
    return ECDH_MODP_DH_D58_OK;
}
