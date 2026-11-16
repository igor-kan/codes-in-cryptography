#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t ikm[32], prk[32];
    for (int i = 0; i < 32; ++i) ikm[i] = (uint8_t)i;
    assert(hkdf_extract(NULL, 0, ikm, 32, prk) == HKDF_SHA256_RFC5869_OK);
    uint8_t out_mt[8 * 48];
    assert(hkdf_batch_derive_mt(prk, 8, 48, out_mt, 4) == HKDF_SHA256_RFC5869_OK);
    for (int i = 1; i < 8; ++i) {
        assert(memcmp(out_mt + (i - 1) * 48, out_mt + i * 48, 48) != 0);
    }
    return 0;
}
