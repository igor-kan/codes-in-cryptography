#include "interface.h"

sha1_rfc3174_compat_err_t sha1_validate_ctx(const sha1_ctx_t* ctx) {
    if (!ctx) return SHA1_RFC3174_COMPAT_ERR_NULL;
    return SHA1_RFC3174_COMPAT_OK;
}
