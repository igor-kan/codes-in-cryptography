#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(md5_stream_digest_d61_validate_len(1) == MD5_STREAM_DIGEST_D61_OK);
    const uint8_t empty_msg[1] = {0U};
    uint8_t d_empty[16];
    md5_digest_d61(empty_msg, 0U, d_empty);
    const uint8_t ref_empty[16] = {0xd4U, 0x1dU, 0x8cU, 0xd9U, 0x8fU, 0x00U, 0xb2U, 0x04U, 0xe9U, 0x80U, 0x09U, 0x98U, 0xecU, 0xf8U, 0x42U, 0x7eU};
    assert(memcmp(d_empty, ref_empty, 16U) == 0);
    uint8_t d_abc[16];
    md5_digest_d61((const uint8_t*)"abc", 3U, d_abc);
    const uint8_t ref_abc[16] = {0x90U, 0x01U, 0x50U, 0x98U, 0x3cU, 0xd2U, 0x4fU, 0xb0U, 0xd6U, 0x96U, 0x3fU, 0x7dU, 0x28U, 0xe1U, 0x7fU, 0x72U};
    assert(memcmp(d_abc, ref_abc, 16U) == 0);
    uint8_t d_msg[16];
    md5_digest_d61((const uint8_t*)"message digest", 14U, d_msg);
    const uint8_t ref_msg[16] = {0xf9U, 0x6bU, 0x69U, 0x7dU, 0x7cU, 0xb7U, 0x93U, 0x8dU, 0x52U, 0x5aU, 0x2fU, 0x31U, 0xaaU, 0xf1U, 0x61U, 0xd0U};
    assert(memcmp(d_msg, ref_msg, 16U) == 0);
    assert(md5_stream_digest_d61_verify_guard(true) == MD5_STREAM_DIGEST_D61_OK);
    return 0;
}
