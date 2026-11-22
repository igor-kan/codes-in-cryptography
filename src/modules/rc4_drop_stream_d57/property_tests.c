#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(rc4_drop_stream_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t k[4] = {1,2,3,4};
    uint8_t d[4] = {9,8,7,6};
    rc4_drop_xor(k, 4, 128, d, 4);
    rc4_drop_xor(k, 4, 128, d, 4);
    assert(d[0] == 9 && d[3] == 6);
    return 0;
}
