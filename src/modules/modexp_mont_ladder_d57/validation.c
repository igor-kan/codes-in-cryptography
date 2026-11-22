#include "interface.h"

modexp_mont_ladder_d57_err_t modexp_mont_ladder_d57_validate_len(size_t n) {
    if (n == 0) {
        return MODEXP_MONT_LADDER_D57_ERR_INVALID;
    }
    return MODEXP_MONT_LADDER_D57_OK;
}
