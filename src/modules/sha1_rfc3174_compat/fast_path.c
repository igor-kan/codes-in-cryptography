#include "interface.h"

void sha1_oneshot(const uint8_t* data, size_t len, uint8_t digest[20]) {
    sha1_ctx_t ctx;
    sha1_init(&ctx);
    if (len > 0 && data) sha1_update(&ctx, data, len);
    sha1_final(&ctx, digest);
}
