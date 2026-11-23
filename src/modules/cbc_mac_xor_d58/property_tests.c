#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(cbc_mac_xor_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint64_t x[1] = {42ULL};
    uint64_t t = cbc_mac64(99ULL, x, 1);
    const uint64_t ext[2] = {42ULL, t ^ 42ULL};
    assert(cbc_mac64(99ULL, ext, 2) != t);
    return 0;
}
