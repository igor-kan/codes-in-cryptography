#include "interface.h"
#include <assert.h>

int main(void) {
    uint64_t ids[3] = {2, 4, 7};
    assert(validate_signer_ids(ids, 3) == FROST_THRESHOLD_COMBINE_OK);
    uint64_t sum = 0;
    for (size_t i = 0; i < 3; ++i) {
        uint64_t lam = 0;
        assert(frost_lagrange_coeff(ids, 3, i, &lam) == FROST_THRESHOLD_COMBINE_OK);
        sum = mod_add_q(sum, lam);
    }
    assert(sum == 1ULL);
    return 0;
}
