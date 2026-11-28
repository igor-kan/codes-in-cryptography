#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(xxh64_block_hash_d61_validate_len(1) == XXH64_BLOCK_HASH_D61_OK);
    const uint8_t empty[1] = {0U};
    assert(xxh64_d61(empty, 0U, 0ULL) == 0xEF46DB3751D8E999ULL);
    const uint8_t abc[3] = {'a', 'b', 'c'};
    assert(xxh64_d61(abc, 3U, 0ULL) == 0x44BC2CF5AD770999ULL);
    assert(xxh64_block_hash_d61_verify_guard(true) == XXH64_BLOCK_HASH_D61_OK);
    return 0;
}
