#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(solovay_strassen_jacobi_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    assert(solovay_strassen_prime(2147483647ULL));
    assert(!solovay_strassen_prime(1729ULL));
    return 0;
}
