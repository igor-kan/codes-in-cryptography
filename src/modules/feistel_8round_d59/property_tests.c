#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(feistel_8round_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t rk[8] = {10u,20u,30u,40u,50u,60u,70u,80u};
    assert(feistel8_enc(1ULL, rk) != feistel8_enc(2ULL, rk));
    return 0;
}
