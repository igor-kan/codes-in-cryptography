#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(rc4_drop3072_stream_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t key[4] = {9,8,7,6}, b[4] = {0}; rc4_state_t s; rc4_drop_init(&s, key, 4, 3072); rc4_xor(&s, b, 4); assert(b[0] != 0 || b[1] != 0);
    return 0;
}
