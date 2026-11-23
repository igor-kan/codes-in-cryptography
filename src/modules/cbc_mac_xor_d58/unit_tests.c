#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(cbc_mac_xor_d58_validate_len(1) == CBC_MAC_XOR_D58_OK);
    const uint64_t b1[2] = {10ULL, 20ULL};
    const uint64_t b2[2] = {10ULL, 21ULL};
    assert(cbc_mac64(777ULL, b1, 2) != cbc_mac64(777ULL, b2, 2));
    assert(cbc_mac_xor_d58_verify_guard(true) == CBC_MAC_XOR_D58_OK);
    return 0;
}
