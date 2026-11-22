#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(hkdf_extract_exp_d57_validate_len(1) == HKDF_EXTRACT_EXP_D57_OK);
    const uint8_t s[4] = {1,2,3,4}, ikm[4] = {5,6,7,8};
    const uint8_t c1[3] = {'e','n','c'}, c2[3] = {'m','a','c'};
    uint64_t prk = hkdf_extract64(s, 4, ikm, 4);
    assert(hkdf_expand64(prk, c1, 3, 1) != hkdf_expand64(prk, c2, 3, 1));
    assert(hkdf_extract_exp_d57_verify_guard(true) == HKDF_EXTRACT_EXP_D57_OK);
    return 0;
}
