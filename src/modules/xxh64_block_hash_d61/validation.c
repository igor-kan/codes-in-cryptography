#include "interface.h"

xxh64_block_hash_d61_err_t xxh64_block_hash_d61_validate_len(size_t n) {
    if (n == 0) {
        return XXH64_BLOCK_HASH_D61_ERR_INVALID;
    }
    return XXH64_BLOCK_HASH_D61_OK;
}
