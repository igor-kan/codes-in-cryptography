#include "interface.h"
#include <assert.h>

int main(void) {
    kek128_t kek = {0x1111222233334444ULL, 0x5555666677778888ULL};
    uint64_t a[4] = {1,2,3,4}, b[4] = {5,6,7,8}, ca[5], cb[5], ra[4], rb[4];
    rfc3394_parallel_wrap(kek, a, b, 4, ca, cb);
    assert(rfc3394_unwrap(kek, ca, 4, ra) == RFC3394_KEYWRAP_CIPHER_OK);
    assert(rfc3394_unwrap(kek, cb, 4, rb) == RFC3394_KEYWRAP_CIPHER_OK);
    for (int i = 0; i < 4; ++i) assert(ra[i] == a[i] && rb[i] == b[i]);
    return 0;
}
