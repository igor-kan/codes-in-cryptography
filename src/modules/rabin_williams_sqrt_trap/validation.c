#include "interface.h"

rabin_williams_sqrt_trap_err_t rabin_williams_sqrt_trap_validate_len(size_t n) {
    if (n == 0) {
        return RABIN_WILLIAMS_SQRT_TRAP_ERR_INVALID;
    }
    return RABIN_WILLIAMS_SQRT_TRAP_OK;
}
