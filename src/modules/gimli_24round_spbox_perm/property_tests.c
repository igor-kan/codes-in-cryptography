#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(gimli_24round_spbox_perm_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    gimli_state_t a = {{0}}, b = {{1}};
    gimli_permute(&a); gimli_permute(&b);
    assert(a.s[0] != b.s[0]);
    return 0;
}
