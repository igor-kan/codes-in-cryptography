#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(pbkdf2_iterated_stretch_d56_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t p[3] = {1, 2, 3};
    const uint8_t s[2] = {4, 5};
    assert(stretch_kdf64(p, 3, s, 2, 8) != stretch_kdf64(p, 3, s, 2, 9));
    return 0;
}
