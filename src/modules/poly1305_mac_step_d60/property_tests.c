#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(poly1305_mac_step_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t key[32]; for (int i=0;i<32;++i) key[i]=(uint8_t)(i+5);
    uint8_t blk1[16], blk2[16], m1[16], m2[16];
    for (int i=0;i<16;++i) { blk1[i]=(uint8_t)i; blk2[i]=(uint8_t)i; }
    blk2[15] ^= 1U;
    poly1305_state_t s1, s2;
    poly1305_init_d60(&s1, key); poly1305_block_d60(&s1, blk1); poly1305_finish_d60(&s1, m1);
    poly1305_init_d60(&s2, key); poly1305_block_d60(&s2, blk2); poly1305_finish_d60(&s2, m2);
    assert(memcmp(m1, m2, 16) != 0);
    return 0;
}
