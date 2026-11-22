#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(modexp_mont_ladder_d57_validate_len(1) == MODEXP_MONT_LADDER_D57_OK);
    assert(mont_ladder_modexp(2ULL, 10ULL, 1000ULL) == 24ULL);
    assert(mont_ladder_modexp(7ULL, 1000000006ULL, 1000000007ULL) == 1ULL);
    assert(modexp_mont_ladder_d57_verify_guard(true) == MODEXP_MONT_LADDER_D57_OK);
    return 0;
}
