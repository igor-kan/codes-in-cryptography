#include "interface.h"

elgamal_multiplicative_hom_err_t elgamal_multiplicative_hom_validate_len(size_t n) {
    if (n == 0) {
        return ELGAMAL_MULTIPLICATIVE_HOM_ERR_INVALID;
    }
    return ELGAMAL_MULTIPLICATIVE_HOM_OK;
}
