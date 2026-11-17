#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t key[16] = {9};
    uint8_t msgs[64];
    for (size_t i = 0; i < 64; ++i) msgs[i] = (uint8_t)i;
    uint8_t tags[4 * 16];
    xoodyak_parallel_macs(key, msgs, 16, 4, tags);
    assert(memcmp(tags, tags + 16, 16) != 0);
    assert(memcmp(tags + 16, tags + 32, 16) != 0);
    return 0;
}
