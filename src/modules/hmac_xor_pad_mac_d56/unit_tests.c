#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(hmac_xor_pad_mac_d56_validate_len(1) == HMAC_XOR_PAD_MAC_D56_OK);
    const uint8_t key[4] = {0xAA, 0xBB, 0xCC, 0xDD};
    const uint8_t msg[5] = {'h','e','l','l','o'};
    uint64_t t1 = nested_hmac64(key, 4, msg, 5);
    uint64_t t2 = nested_hmac64(key, 4, msg, 5);
    assert(verify_hmac64(t1, t2) == 1);
    assert(hmac_xor_pad_mac_d56_verify_guard(true) == HMAC_XOR_PAD_MAC_D56_OK);
    return 0;
}
