#include "interface.h"

xxh64_block_hash_d61_err_t xxh64_block_hash_d61_verify_guard(bool cond) {
    if (!cond) {
        return XXH64_BLOCK_HASH_D61_ERR_INVARIANT;
    }
    return XXH64_BLOCK_HASH_D61_OK;
}
