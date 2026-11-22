#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(speck64_128_arx_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t k[4] = {1u,2u,3u,4u}, rk[27], p[2] = {99u, 100u};
    speck64_expand(k, rk);
    speck64_enc(p, rk); speck64_dec(p, rk);
    assert(p[0] == 99u && p[1] == 100u);
    return 0;
}
