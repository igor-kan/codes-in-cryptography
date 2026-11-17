#include "interface.h"
#include <assert.h>

int main(void) {
    uint64_t p = 1000000007ULL, g = 5ULL;
    uint64_t tgts[2] = {pow_mod64(g, 123ULL, p), pow_mod64(g, 987ULL, p)};
    dlog_result_t out[2];
    parallel_kangaroo_solve(g, tgts, 2, p, 0, 2000ULL, out);
    assert(out[0].found && out[0].exponent == 123ULL);
    assert(out[1].found && out[1].exponent == 987ULL);
    return 0;
}
