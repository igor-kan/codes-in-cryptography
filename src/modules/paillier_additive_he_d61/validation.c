#include "interface.h"

paillier_additive_he_d61_err_t paillier_additive_he_d61_validate_len(size_t n) {
    if (n == 0) {
        return PAILLIER_ADDITIVE_HE_D61_ERR_INVALID;
    }
    return PAILLIER_ADDITIVE_HE_D61_OK;
}
