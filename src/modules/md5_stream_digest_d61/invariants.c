#include "interface.h"

md5_stream_digest_d61_err_t md5_stream_digest_d61_verify_guard(bool cond) {
    if (!cond) {
        return MD5_STREAM_DIGEST_D61_ERR_INVARIANT;
    }
    return MD5_STREAM_DIGEST_D61_OK;
}
