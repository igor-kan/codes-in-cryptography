#include "interface.h"

hkdf_extract_exp_d57_err_t hkdf_extract_exp_d57_validate_len(size_t n) {
    if (n == 0) {
        return HKDF_EXTRACT_EXP_D57_ERR_INVALID;
    }
    return HKDF_EXTRACT_EXP_D57_OK;
}
