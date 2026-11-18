#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(schnorr_musig2_nonce_agg_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    musig_nonce_t ns[1] = {{5, 7, musig_pow_p(MUSIG_G, 5), musig_pow_p(MUSIG_G, 7)}};
    assert(musig_agg_pub_nonce(ns, 1, 2) == musig_pow_p(MUSIG_G, 19));
    return 0;
}
