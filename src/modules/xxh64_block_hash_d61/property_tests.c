#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(xxh64_block_hash_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t buf[80];
    for (int i = 0; i < 80; ++i) buf[i] = (uint8_t)(i * 5 + 1);
    uint64_t h1 = xxh64_d61(buf, 80U, 12345ULL);
    buf[37] ^= 0x01U;
    uint64_t h2 = xxh64_d61(buf, 80U, 12345ULL);
    assert(h1 != h2);
    assert(xxh64_d61(buf, 80U, 12345ULL) == h2);
    assert(xxh64_d61(buf, 80U, 999ULL) != h2);
    return 0;
}
