#include "interface.h"
#include <assert.h>

int main(void) {
    assert(aes128_verify_fips197_b() == AES128_FIPS197_CIPHER_OK);
    return 0;
}
