#include "interface.h"

elgamal_multiplicative_hom_err_t elgamal_multiplicative_hom_verify_guard(bool cond) {
    if (!cond) {
        return ELGAMAL_MULTIPLICATIVE_HOM_ERR_INVARIANT;
    }
    return ELGAMAL_MULTIPLICATIVE_HOM_OK;
}
