#include "interface.h"

elgamal_schnorr_zkp_err_t elgamal_schnorr_zkp_validate_len(size_t n) {
    if (n == 0) {
        return ELGAMAL_SCHNORR_ZKP_ERR_INVALID;
    }
    return ELGAMAL_SCHNORR_ZKP_OK;
}
