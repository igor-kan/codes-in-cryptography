#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    const uint8_t pk[21] = {0x00, 0x01,0x09,0x66,0x77,0x60,0x06,0x95,0x3d,0x55,0x67,0x43,0x9e,0x5e,0x39,0xf8,0x6a,0x0d,0x27,0x3b,0xee};
    char addr[64];
    size_t al = 0, dl = 0;
    assert(b58check_encode(pk, 21, addr, sizeof(addr), &al) == BASE58CHECK_BTC_CODEC_OK);
    assert(strcmp(addr, "16UwLL9Risc3QfPqBUvKofHmBQ7wMtjvM") == 0);
    uint8_t out[32];
    assert(b58check_decode(addr, al, out, sizeof(out), &dl) == BASE58CHECK_BTC_CODEC_OK);
    assert(dl == 21 && memcmp(pk, out, 21) == 0);
    addr[5] = (addr[5] == 'a') ? 'b' : 'a';
    assert(b58check_decode(addr, al, out, sizeof(out), &dl) == BASE58CHECK_BTC_CODEC_ERR_INVARIANT);
    return 0;
}
