#include "interface.h"
#include <assert.h>

int main(void) {
    xtea_key_t key = {{0x11112222U, 0x33334444U, 0x55556666U, 0x77778888U}};
    for (uint32_t i = 0; i < 64; ++i) {
        assert(xtea_cbc_mac_check_bijection(&key, i * 0x9E37U, ~i) == XTEA_CBC_MAC_OK);
    }
    return 0;
}
