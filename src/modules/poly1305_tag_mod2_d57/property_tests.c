#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(poly1305_tag_mod2_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint64_t m[2] = {7ULL, 11ULL};
    assert(cw61_mac(5ULL, 100ULL, m, 2) != cw61_mac(5ULL, 101ULL, m, 2));
    return 0;
}
