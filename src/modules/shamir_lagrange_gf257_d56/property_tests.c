#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(shamir_lagrange_gf257_d56_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    int coeffs[3] = {123, 7, 99};
    gf257_share_t subA[3] = {{1, gf257_eval_poly(coeffs, 3, 1)}, {2, gf257_eval_poly(coeffs, 3, 2)}, {3, gf257_eval_poly(coeffs, 3, 3)}};
    gf257_share_t subB[3] = {{2, gf257_eval_poly(coeffs, 3, 2)}, {4, gf257_eval_poly(coeffs, 3, 4)}, {5, gf257_eval_poly(coeffs, 3, 5)}};
    assert(gf257_reconstruct_secret(subA, 3) == gf257_reconstruct_secret(subB, 3));
    return 0;
}
