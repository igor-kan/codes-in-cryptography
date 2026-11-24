#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(salsa20_qr_core_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t s[16], o[16]; for (uint32_t i = 0; i < 16; ++i) s[i] = i + 1;
    salsa20_core(s, o);
    assert(o[0] != s[0] && o[15] != s[15]);
    return 0;
}
