#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(siphash_2_4_prf_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t m1[8] = {1,2,3,4,5,6,7,8}, m2[8] = {1,2,3,4,5,6,7,9};
    assert(siphash24_d60(1ULL, 2ULL, m1, 8) != siphash24_d60(1ULL, 2ULL, m2, 8));
    return 0;
}
