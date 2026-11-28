#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(threefish256_arx_d61_validate_len(1) == THREEFISH256_ARX_D61_OK);
    uint64_t key[4] = {1ULL, 2ULL, 3ULL, 4ULL};
    uint64_t tw[2] = {5ULL, 6ULL};
    uint64_t pt[4] = {7ULL, 8ULL, 9ULL, 10ULL};
    uint64_t ct[4], back[4];
    threefish256_encrypt_d61(key, tw, pt, ct);
    threefish256_decrypt_d61(key, tw, ct, back);
    assert(memcmp(pt, back, sizeof(pt)) == 0);
    assert(ct[0] != pt[0]);
    assert(threefish256_arx_d61_verify_guard(true) == THREEFISH256_ARX_D61_OK);
    return 0;
}
