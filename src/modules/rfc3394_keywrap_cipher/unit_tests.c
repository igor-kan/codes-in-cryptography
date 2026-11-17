#include "interface.h"
#include <assert.h>

int main(void) {
    kek128_t kek = {0x0001020304050607ULL, 0x08090A0B0C0D0E0FULL};
    uint64_t pt[2] = {0x0011223344556677ULL, 0x8899AABBCCDDEEFFULL};
    assert(rfc3394_verify_tamper_detection(kek, pt, 2) == RFC3394_KEYWRAP_CIPHER_OK);
    return 0;
}
