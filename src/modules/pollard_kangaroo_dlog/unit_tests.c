#include "interface.h"
#include <assert.h>

int main(void) {
    uint64_t p = 1000000007ULL, g = 5ULL, secret = 4321ULL;
    uint64_t h = pow_mod64(g, secret, p);
    dlog_result_t res = kangaroo_solve(g, h, p, 0, 10000ULL);
    assert(verify_dlog_solution(g, h, p, &res) == POLLARD_KANGAROO_DLOG_OK);
    assert(res.exponent == secret);
    return 0;
}
