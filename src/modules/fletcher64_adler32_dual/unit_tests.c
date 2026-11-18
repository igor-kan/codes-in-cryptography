#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(fletcher64_adler32_dual_validate_len(1) == FLETCHER64_ADLER32_DUAL_OK);
    const uint8_t* wiki = (const uint8_t*)"Wikipedia";
    assert(compute_adler32(wiki, 9) == 0x11E60398U);
    uint32_t w[2] = {1, 2};
    assert(compute_fletcher64(w, 2) == ((4ULL << 32) | 3ULL));
    assert(fletcher64_adler32_dual_verify_guard(true) == FLETCHER64_ADLER32_DUAL_OK);
    return 0;
}
