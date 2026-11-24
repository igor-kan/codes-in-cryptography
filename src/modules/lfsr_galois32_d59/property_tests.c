#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(lfsr_galois32_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t s = 0u;
    (void)galois32_step(&s);
    assert(s != 0u);
    return 0;
}
