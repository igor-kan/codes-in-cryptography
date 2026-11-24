#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(rabin_miller_u64_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    assert(is_prime_u64(1ULL) == 0 && is_prime_u64(2ULL) == 1 && is_prime_u64(4ULL) == 0);
    return 0;
}
