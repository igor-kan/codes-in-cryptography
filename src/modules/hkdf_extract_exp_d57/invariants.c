#include "interface.h"

hkdf_extract_exp_d57_err_t hkdf_extract_exp_d57_verify_guard(bool cond) {
    if (!cond) {
        return HKDF_EXTRACT_EXP_D57_ERR_INVARIANT;
    }
    return HKDF_EXTRACT_EXP_D57_OK;
}
