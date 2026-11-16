#include "interface.h"
#include <string.h>

sha1_rfc3174_compat_err_t sha1_verify_rfc3174_vectors(void) {
    const uint8_t exp_abc[20] = {
        0xa9,0x99,0x3e,0x36,0x47,0x06,0x81,0x6a,0xba,0x3e,
        0x25,0x71,0x78,0x50,0xc2,0x6c,0x9c,0xd0,0xd8,0x9d
    };
    uint8_t d[20];
    sha1_oneshot((const uint8_t*)"abc", 3, d);
    if (memcmp(d, exp_abc, 20) != 0) return SHA1_RFC3174_COMPAT_ERR_INVARIANT;

    const char* long_msg = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    const uint8_t exp_56[20] = {
        0x84,0x98,0x3e,0x44,0x1c,0x3b,0xd2,0x6e,0xba,0xae,
        0x4a,0xa1,0xf9,0x51,0x29,0xe5,0xe5,0x46,0x70,0xf1
    };
    sha1_ctx_t ctx;
    sha1_init(&ctx);
    sha1_update(&ctx, (const uint8_t*)long_msg, 20);
    sha1_update(&ctx, (const uint8_t*)long_msg + 20, 36);
    sha1_final(&ctx, d);
    if (memcmp(d, exp_56, 20) != 0) return SHA1_RFC3174_COMPAT_ERR_INVARIANT;
    return SHA1_RFC3174_COMPAT_OK;
}
