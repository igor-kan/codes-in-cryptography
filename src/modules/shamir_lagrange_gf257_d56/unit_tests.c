#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(shamir_lagrange_gf257_d56_validate_len(1) == SHAMIR_LAGRANGE_GF257_D56_OK);
    int coeffs[3] = {199, 43, 17};
    gf257_share_t sh[5];
    for (int i = 0; i < 5; ++i) {
        sh[i].x = i + 1;
        sh[i].y = gf257_eval_poly(coeffs, 3, i + 1);
    }
    gf257_share_t pick[3] = {sh[0], sh[2], sh[4]};
    assert(gf257_reconstruct_secret(pick, 3) == 199);
    assert(shamir_lagrange_gf257_d56_verify_guard(true) == SHAMIR_LAGRANGE_GF257_D56_OK);
    return 0;
}
