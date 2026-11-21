#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(feistel_balanced_prp_d56_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t rk[4] = {9u, 8u, 7u, 6u};
    assert(feistel4_enc(100ULL, rk) != feistel4_enc(101ULL, rk));
    return 0;
}
