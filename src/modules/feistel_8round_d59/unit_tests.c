#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(feistel_8round_d59_validate_len(1) == FEISTEL_8ROUND_D59_OK);
    uint32_t rk[8] = {1u,2u,3u,4u,5u,6u,7u,8u};
    uint64_t pt = 0xDEADBEEFCAFEBABEULL;
    uint64_t ct = feistel8_enc(pt, rk);
    assert(ct != pt && feistel8_dec(ct, rk) == pt);
    assert(feistel_8round_d59_verify_guard(true) == FEISTEL_8ROUND_D59_OK);
    return 0;
}
