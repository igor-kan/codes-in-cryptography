#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(gf256_aes_mul_inv_d56_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    for (int x = 1; x < 256; x += 17) {
        uint8_t inv = gf256_inv((uint8_t)x);
        assert(gf256_mul((uint8_t)x, inv) == 1u);
    }
    return 0;
}
