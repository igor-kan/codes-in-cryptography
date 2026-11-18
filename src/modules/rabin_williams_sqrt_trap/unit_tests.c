#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(rabin_williams_sqrt_trap_validate_len(1) == RABIN_WILLIAMS_SQRT_TRAP_OK);
    rabin_key_t rk = {103ULL, 107ULL, 103ULL * 107ULL};
    uint64_t m = 1234ULL, c = rabin_encrypt(&rk, m), r[4];
    rabin_decrypt_roots(&rk, c, r);
    bool found = false;
    for (int i = 0; i < 4; ++i) {
        assert(rabin_encrypt(&rk, r[i]) == c);
        if (r[i] == m) found = true;
    }
    assert(found);
    assert(rabin_williams_sqrt_trap_verify_guard(true) == RABIN_WILLIAMS_SQRT_TRAP_OK);
    return 0;
}
