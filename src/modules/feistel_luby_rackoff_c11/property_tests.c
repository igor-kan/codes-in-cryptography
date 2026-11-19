#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(feistel_luby_rackoff_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    lr_key_t k = {{1, 2, 3, 4}}; assert(lr_decrypt64(k, lr_encrypt64(k, 0ULL)) == 0ULL);
    return 0;
}
