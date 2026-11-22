#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(modexp_mont_ladder_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    assert(mont_ladder_modexp(3ULL, 0ULL, 97ULL) == 1ULL);
    assert(mont_ladder_modexp(5ULL, 13ULL, 23ULL) == 21ULL);
    return 0;
}
