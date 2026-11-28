#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(ripemd160_digest_d61_validate_len(1) == RIPEMD160_DIGEST_D61_OK);
    const uint8_t empty_msg[1] = {0U};
    uint8_t d_empty[20];
    ripemd160_digest_d61(empty_msg, 0U, d_empty);
    const uint8_t ref_empty[20] = {0x9cU, 0x11U, 0x85U, 0xa5U, 0xc5U, 0xe9U, 0xfcU, 0x54U, 0x61U, 0x28U, 0x08U, 0x97U, 0x7eU, 0xe8U, 0xf5U, 0x48U, 0xb2U, 0x25U, 0x8dU, 0x31U};
    assert(memcmp(d_empty, ref_empty, 20U) == 0);
    uint8_t d_abc[20];
    ripemd160_digest_d61((const uint8_t*)"abc", 3U, d_abc);
    const uint8_t ref_abc[20] = {0x8eU, 0xb2U, 0x08U, 0xf7U, 0xe0U, 0x5dU, 0x98U, 0x7aU, 0x9bU, 0x04U, 0x4aU, 0x8eU, 0x98U, 0xc6U, 0xb0U, 0x87U, 0xf1U, 0x5aU, 0x0bU, 0xfcU};
    assert(memcmp(d_abc, ref_abc, 20U) == 0);
    uint8_t d_msg[20];
    ripemd160_digest_d61((const uint8_t*)"message digest", 14U, d_msg);
    const uint8_t ref_msg[20] = {0x5dU, 0x06U, 0x89U, 0xefU, 0x49U, 0xd2U, 0xfaU, 0xe5U, 0x72U, 0xb8U, 0x81U, 0xb1U, 0x23U, 0xa8U, 0x5fU, 0xfaU, 0x21U, 0x59U, 0x5fU, 0x36U};
    assert(memcmp(d_msg, ref_msg, 20U) == 0);
    assert(ripemd160_digest_d61_verify_guard(true) == RIPEMD160_DIGEST_D61_OK);
    return 0;
}
