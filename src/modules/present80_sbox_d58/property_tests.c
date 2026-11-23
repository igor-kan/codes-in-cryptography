#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(present80_sbox_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    for (uint8_t x = 0; x < 16; ++x) {
        assert(spn_inv_sbox(spn_apply_sbox(x)) == x);
    }
    return 0;
}
