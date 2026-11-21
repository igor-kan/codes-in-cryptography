#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(feistel_balanced_prp_d56_validate_len(1) == FEISTEL_BALANCED_PRP_D56_OK);
    uint32_t rk[4] = {0x1111u, 0x2222u, 0x3333u, 0x4444u};
    uint64_t pt = 0x123456789ABCDEF0ULL;
    uint64_t ct = feistel4_enc(pt, rk);
    assert(ct != pt && feistel4_dec(ct, rk) == pt);
    assert(feistel_balanced_prp_d56_verify_guard(true) == FEISTEL_BALANCED_PRP_D56_OK);
    return 0;
}
