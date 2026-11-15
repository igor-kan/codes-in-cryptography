#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    xtea_key_t key = {{0x27f917b1U, 0xc1da8993U, 0x60e2acaaU, 0xa6eb923dU}};
    assert(xtea_cbc_mac_check_bijection(&key, 0xaf20a390U, 0x547571aaU) == XTEA_CBC_MAC_OK);
    uint8_t msg[17] = "0123456789ABCDEF";
    uint8_t tag1[8], tag2[8];
    assert(xtea_cbc_mac_compute(&key, msg, 2, tag1) == XTEA_CBC_MAC_OK);
    msg[3] ^= 1U;
    assert(xtea_cbc_mac_compute(&key, msg, 2, tag2) == XTEA_CBC_MAC_OK);
    assert(memcmp(tag1, tag2, 8) != 0);
    return 0;
}
