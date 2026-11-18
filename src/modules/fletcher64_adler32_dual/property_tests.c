#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(fletcher64_adler32_dual_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t* a = (const uint8_t*)"ab";
    const uint8_t* b = (const uint8_t*)"ba";
    assert(compute_adler32(a, 2) != compute_adler32(b, 2));
    return 0;
}
