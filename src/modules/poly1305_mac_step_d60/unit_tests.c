#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(poly1305_mac_step_d60_validate_len(1) == POLY1305_MAC_STEP_D60_OK);
    uint8_t key[32]; memset(key, 0, sizeof(key)); key[0] = 1; key[16] = 7;
    uint8_t blk[16]; memset(blk, 0, sizeof(blk)); blk[0] = 2;
    uint8_t mac[16];
    poly1305_state_t st; poly1305_init_d60(&st, key);
    poly1305_block_d60(&st, blk); poly1305_finish_d60(&st, mac);
    assert(mac[0] == 9U);
    assert(poly1305_mac_step_d60_verify_guard(true) == POLY1305_MAC_STEP_D60_OK);
    return 0;
}
