#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(pedersen_commit_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint64_t c1 = pedersen_commit_d60(40ULL, 123ULL);
    uint64_t c2 = pedersen_commit_d60(65ULL, 456ULL);
    uint64_t prod = (uint64_t)(((__uint128_t)c1 * c2) % PED_P);
    assert(pedersen_verify_d60(prod, 105ULL, 579ULL));
    return 0;
}
