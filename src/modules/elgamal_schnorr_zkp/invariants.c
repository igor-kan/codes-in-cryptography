#include "interface.h"

elgamal_schnorr_zkp_err_t elgamal_schnorr_zkp_verify_guard(bool cond) {
    if (!cond) {
        return ELGAMAL_SCHNORR_ZKP_ERR_INVARIANT;
    }
    return ELGAMAL_SCHNORR_ZKP_OK;
}
