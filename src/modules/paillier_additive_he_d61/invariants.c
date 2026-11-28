#include "interface.h"

paillier_additive_he_d61_err_t paillier_additive_he_d61_verify_guard(bool cond) {
    if (!cond) {
        return PAILLIER_ADDITIVE_HE_D61_ERR_INVARIANT;
    }
    return PAILLIER_ADDITIVE_HE_D61_OK;
}
