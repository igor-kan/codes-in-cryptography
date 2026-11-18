#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(rabin_williams_sqrt_trap_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    rabin_key_t rk = {19ULL, 23ULL, 437ULL};
    uint64_t r[4]; rabin_decrypt_roots(&rk, rabin_encrypt(&rk, 77ULL), r);
    assert(rabin_encrypt(&rk, r[0]) == rabin_encrypt(&rk, 77ULL));
    return 0;
}
