#include "interface.h"
#include <assert.h>

int main(void) {
    assert(hkdf_verify_rfc5869_a1() == HKDF_SHA256_RFC5869_OK);
    uint8_t prk[32] = {1}, okm[64];
    assert(hkdf_expand(prk, NULL, 0, okm, 255U * 32U + 1U) == HKDF_SHA256_RFC5869_ERR_BOUNDS);
    return 0;
}
