#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(hkdf_extract_exp_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t info[2] = {'k','1'};
    assert(hkdf_expand64(123ULL, info, 2, 1) != hkdf_expand64(123ULL, info, 2, 2));
    return 0;
}
