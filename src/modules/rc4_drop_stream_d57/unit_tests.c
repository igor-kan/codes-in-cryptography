#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(rc4_drop_stream_d57_validate_len(1) == RC4_DROP_STREAM_D57_OK);
    const uint8_t key[3] = {'K','e','y'};
    uint8_t buf[9] = {'P','l','a','i','n','t','e','x','t'};
    uint8_t orig[9]; memcpy(orig, buf, 9);
    rc4_drop_xor(key, 3, 256, buf, 9);
    assert(memcmp(buf, orig, 9) != 0);
    rc4_drop_xor(key, 3, 256, buf, 9);
    assert(memcmp(buf, orig, 9) == 0);
    assert(rc4_drop_stream_d57_verify_guard(true) == RC4_DROP_STREAM_D57_OK);
    return 0;
}
