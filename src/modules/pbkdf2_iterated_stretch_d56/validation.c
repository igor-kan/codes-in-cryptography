#include "interface.h"

pbkdf2_iterated_stretch_d56_err_t pbkdf2_iterated_stretch_d56_validate_len(size_t n) {
    if (n == 0) {
        return PBKDF2_ITERATED_STRETCH_D56_ERR_INVALID;
    }
    return PBKDF2_ITERATED_STRETCH_D56_OK;
}
