#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(otp_hmac_counter_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    for (uint64_t cnt = 0; cnt < 20; ++cnt) {
        assert(hotp6_generate(999ULL, cnt) < 1000000u);
    }
    return 0;
}
