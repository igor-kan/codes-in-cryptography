#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(gcm_ghash_gf128_d58_validate_len(1) == GCM_GHASH_GF128_D58_OK);
    assert(gf64_mul(0x12345ULL, 0x6789ULL) == gf64_mul(0x6789ULL, 0x12345ULL));
    assert(gf64_mul(99ULL, 1ULL) == 99ULL);
    assert(gcm_ghash_gf128_d58_verify_guard(true) == GCM_GHASH_GF128_D58_OK);
    return 0;
}
