#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(simon64_128_bit_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t k[4] = {10u,20u,30u,40u}, rk[44], d[2] = {1234u, 5678u};
    simon64_expand(k, rk);
    simon64_enc(d, rk); simon64_dec(d, rk);
    assert(d[0] == 1234u && d[1] == 5678u);
    return 0;
}
