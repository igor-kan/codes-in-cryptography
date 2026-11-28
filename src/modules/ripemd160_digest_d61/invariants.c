#include "interface.h"

ripemd160_digest_d61_err_t ripemd160_digest_d61_verify_guard(bool cond) {
    if (!cond) {
        return RIPEMD160_DIGEST_D61_ERR_INVARIANT;
    }
    return RIPEMD160_DIGEST_D61_OK;
}
