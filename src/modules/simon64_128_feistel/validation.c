#include "interface.h"

simon64_128_feistel_err_t simon64_validate_ptr(const void* p) {
    return p ? SIMON64_128_FEISTEL_OK : SIMON64_128_FEISTEL_ERR_NULL;
}
