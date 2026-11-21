#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(chacha_quarter_round_d56_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t s[16];
    uint32_t out[16];
    for (uint32_t i = 0; i < 16; ++i) s[i] = i + 0x61707865u;
    chacha20_block_words(s, out);
    assert(out[0] != s[0] && out[15] != s[15]);
    return 0;
}
