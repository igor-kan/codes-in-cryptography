#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(present80_sbox_d58_validate_len(1) == PRESENT80_SBOX_D58_OK);
    uint64_t pt = 0x0123456789ABCDEFULL;
    uint64_t st = spn_permute64(spn_apply_sbox(pt));
    assert(spn_inv_sbox(spn_inv_permute64(st)) == pt);
    assert(present80_sbox_d58_verify_guard(true) == PRESENT80_SBOX_D58_OK);
    return 0;
}
