#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(blakley_hyperplane_share_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    hyperplane_share_t a = blak_deal_share(42ULL, 99ULL, 1ULL, 2ULL);
    hyperplane_share_t b = blak_deal_share(42ULL, 99ULL, 4ULL, 3ULL);
    assert(blak_recover_secret(a, b) == 42ULL);
    return 0;
}
