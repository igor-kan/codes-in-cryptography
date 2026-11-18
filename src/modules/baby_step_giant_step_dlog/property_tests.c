#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(baby_step_giant_step_dlog_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint64_t p = 65537ULL, g = 3ULL;
    assert(shanks_bsgs_dlog(g, bsgs_pow_mod(g, 1234ULL, p), p) == 1234);
    return 0;
}
