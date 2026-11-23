#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(tea_classic_64_d58_validate_len(1) == TEA_CLASSIC_64_D58_OK);
    uint32_t k[4] = {10u, 20u, 30u, 40u}, v[2] = {0x11223344u, 0x55667788u};
    tea_encrypt(v, k);
    assert(v[0] != 0x11223344u);
    tea_decrypt(v, k);
    assert(v[0] == 0x11223344u && v[1] == 0x55667788u);
    assert(tea_classic_64_d58_verify_guard(true) == TEA_CLASSIC_64_D58_OK);
    return 0;
}
