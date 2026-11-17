#include "interface.h"
#include <assert.h>

int main(void) {
    uint32_t key[4] = {0x03020100U, 0x0b0a0908U, 0x13121110U, 0x1b1a1918U};
    uint32_t pt[2] = {0x74206e69U, 0x656b696cU};
    assert(simon64_verify_roundtrip(key, pt) == SIMON64_128_FEISTEL_OK);
    return 0;
}
