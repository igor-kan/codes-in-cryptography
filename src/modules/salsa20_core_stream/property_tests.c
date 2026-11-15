#include "interface.h"
#include <assert.h>

int main(void) {
    uint8_t k[32] = {0}, n[8] = {0}, buf[150];
    for (int i = 0; i < 150; ++i) buf[i] = (uint8_t)(i * 3);
    for (size_t len = 1; len <= 150; len += 17) {
        assert(salsa20_core_stream_check_involution(k, n, buf, len) == SALSA20_CORE_STREAM_OK);
    }
    return 0;
}
