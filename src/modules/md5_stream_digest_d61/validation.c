#include "interface.h"

md5_stream_digest_d61_err_t md5_stream_digest_d61_validate_len(size_t n) {
    if (n == 0) {
        return MD5_STREAM_DIGEST_D61_ERR_INVALID;
    }
    return MD5_STREAM_DIGEST_D61_OK;
}
