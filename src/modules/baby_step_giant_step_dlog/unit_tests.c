#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(baby_step_giant_step_dlog_validate_len(1) == BABY_STEP_GIANT_STEP_DLOG_OK);
    uint64_t p = 10007ULL, g = 5ULL, secret = 4321ULL;
    uint64_t h = bsgs_pow_mod(g, secret, p);
    assert(shanks_bsgs_dlog(g, h, p) == (int64_t)secret);
    assert(baby_step_giant_step_dlog_verify_guard(true) == BABY_STEP_GIANT_STEP_DLOG_OK);
    return 0;
}
