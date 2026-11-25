#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(pedersen_commit_d60_validate_len(1) == PEDERSEN_COMMIT_D60_OK);
    uint64_t c = pedersen_commit_d60(100ULL, 777ULL);
    assert(pedersen_verify_d60(c, 100ULL, 777ULL));
    assert(!pedersen_verify_d60(c, 101ULL, 777ULL));
    assert(pedersen_commit_d60_verify_guard(true) == PEDERSEN_COMMIT_D60_OK);
    return 0;
}
