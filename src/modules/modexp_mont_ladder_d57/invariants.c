#include "interface.h"

modexp_mont_ladder_d57_err_t modexp_mont_ladder_d57_verify_guard(bool cond) {
    if (!cond) {
        return MODEXP_MONT_LADDER_D57_ERR_INVARIANT;
    }
    return MODEXP_MONT_LADDER_D57_OK;
}
