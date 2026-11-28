#include "interface.h"

ripemd160_digest_d61_err_t ripemd160_digest_d61_validate_len(size_t n) {
    if (n == 0) {
        return RIPEMD160_DIGEST_D61_ERR_INVALID;
    }
    return RIPEMD160_DIGEST_D61_OK;
}
