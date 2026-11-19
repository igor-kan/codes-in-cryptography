#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(gf256_inv_affine_sbox_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    assert(aes_sbox_eval(0x01U) == 0x7cU && gf256_mul(0x57U, 0x83U) == 0xc1U);
    return 0;
}
