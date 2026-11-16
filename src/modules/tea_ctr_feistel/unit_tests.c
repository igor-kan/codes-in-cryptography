#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    tea_key_t key = {{0x01234567U, 0x89ABCDEFU, 0xFEDCBA98U, 0x76543210U}};
    assert(tea_verify_involution(&key, 0x11112222U, 0x33334444U) == TEA_CTR_FEISTEL_OK);
    uint8_t msg[37], ct[37], pt[37];
    for (int i = 0; i < 37; ++i) msg[i] = (uint8_t)i;
    tea_ctr_stream(&key, 0xCAFEBABE12345678ULL, msg, ct, 37);
    tea_ctr_stream(&key, 0xCAFEBABE12345678ULL, ct, pt, 37);
    assert(memcmp(msg, pt, 37) == 0 && memcmp(msg, ct, 37) != 0);
    return 0;
}
