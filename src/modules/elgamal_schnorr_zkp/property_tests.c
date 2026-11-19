#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(elgamal_schnorr_zkp_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint64_t sk = 123ULL, pk = zkp_pow_p(ZKP_G, sk);
    schnorr_zkp_t pf = schnorr_prove(sk, 777ULL, 1ULL);
    pf.s ^= 1ULL;
    assert(!schnorr_verify(pk, 1ULL, pf));
    return 0;
}
