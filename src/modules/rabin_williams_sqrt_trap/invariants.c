#include "interface.h"

rabin_williams_sqrt_trap_err_t rabin_williams_sqrt_trap_verify_guard(bool cond) {
    if (!cond) {
        return RABIN_WILLIAMS_SQRT_TRAP_ERR_INVARIANT;
    }
    return RABIN_WILLIAMS_SQRT_TRAP_OK;
}
