#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(chacha20_quarter_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint32_t k[8] = {1,2,3,4,5,6,7,8}, n[3] = {9,10,11};
    uint32_t a[16], b[16];
    chacha20_block_words_d60(k, 1U, n, a);
    chacha20_block_words_d60(k, 2U, n, b);
    assert(a[0] != b[0]);
    return 0;
}
