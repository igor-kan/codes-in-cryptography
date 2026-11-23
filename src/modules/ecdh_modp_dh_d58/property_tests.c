#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(ecdh_modp_dh_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint64_t p = 1000000007ULL;
    assert(dh_pow_mod(5ULL, 0ULL, p) == 1ULL);
    assert(dh_pow_mod(5ULL, 1ULL, p) == 5ULL);
    return 0;
}
