#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(rc4_drop3072_stream_c11_validate_len(1) == RC4_DROP3072_STREAM_C11_OK);
    uint8_t key[8] = {1,2,3,4,5,6,7,8}, msg[5] = {'H','E','L','L','O'}, orig[5] = {'H','E','L','L','O'};
    rc4_state_t s1, s2;
    rc4_drop_init(&s1, key, 8, 3072); rc4_xor(&s1, msg, 5);
    assert(memcmp(msg, orig, 5) != 0);
    rc4_drop_init(&s2, key, 8, 3072); rc4_xor(&s2, msg, 5);
    assert(memcmp(msg, orig, 5) == 0);
    assert(rc4_drop3072_stream_c11_verify_guard(true) == RC4_DROP3072_STREAM_C11_OK);
    return 0;
}
