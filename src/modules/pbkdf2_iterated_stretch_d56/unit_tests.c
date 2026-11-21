#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(pbkdf2_iterated_stretch_d56_validate_len(1) == PBKDF2_ITERATED_STRETCH_D56_OK);
    const uint8_t p[4] = {'p','a','s','s'};
    const uint8_t s1[4] = {'s','l','t','1'};
    const uint8_t s2[4] = {'s','l','t','2'};
    uint64_t k1 = stretch_kdf64(p, 4, s1, 4, 64);
    uint64_t k2 = stretch_kdf64(p, 4, s2, 4, 64);
    assert(k1 != 0 && k1 != k2 && k1 == stretch_kdf64(p, 4, s1, 4, 64));
    assert(pbkdf2_iterated_stretch_d56_verify_guard(true) == PBKDF2_ITERATED_STRETCH_D56_OK);
    return 0;
}
