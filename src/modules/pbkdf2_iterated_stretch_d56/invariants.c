#include "interface.h"

pbkdf2_iterated_stretch_d56_err_t pbkdf2_iterated_stretch_d56_verify_guard(bool cond) {
    if (!cond) {
        return PBKDF2_ITERATED_STRETCH_D56_ERR_INVARIANT;
    }
    return PBKDF2_ITERATED_STRETCH_D56_OK;
}
