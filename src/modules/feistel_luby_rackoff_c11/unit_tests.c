#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(feistel_luby_rackoff_c11_validate_len(1) == FEISTEL_LUBY_RACKOFF_C11_OK);
    lr_key_t k = {{0x1111, 0x2222, 0x3333, 0x4444}};
    uint64_t pt = 0x0123456789abcdefULL;
    uint64_t ct = lr_encrypt64(k, pt);
    assert(ct != pt && lr_decrypt64(k, ct) == pt);
    assert(feistel_luby_rackoff_c11_verify_guard(true) == FEISTEL_LUBY_RACKOFF_C11_OK);
    return 0;
}
