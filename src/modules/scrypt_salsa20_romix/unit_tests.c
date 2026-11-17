#include "interface.h"
#include <assert.h>

int main(void) {
    assert(scrypt_verify_salsa8_rfc() == SCRYPT_SALSA20_ROMIX_OK);
    uint32_t B[32] = {0};
    B[0] = 0x12345678U;
    uint32_t V[16 * 32];
    assert(scrypt_romix(B, 1, 16, V) == SCRYPT_SALSA20_ROMIX_OK);
    assert(B[0] != 0x12345678U);
    return 0;
}
