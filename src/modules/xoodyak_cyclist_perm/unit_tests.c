#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    assert(xoodoo_verify_avalanche() == XOODYAK_CYCLIST_PERM_OK);
    uint8_t key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    uint8_t m1[16] = {0}, m2[16] = {1};
    uint8_t t1[16], t2[16];
    assert(xoodyak_duplex_tag(key, 16, m1, 16, t1) == XOODYAK_CYCLIST_PERM_OK);
    assert(xoodyak_duplex_tag(key, 16, m2, 16, t2) == XOODYAK_CYCLIST_PERM_OK);
    assert(memcmp(t1, t2, 16) != 0);
    return 0;
}
