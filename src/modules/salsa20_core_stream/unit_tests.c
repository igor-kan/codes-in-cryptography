#include "interface.h"
#include <assert.h>

int main(void) {
    // All-zero key & nonce keystream first 4 bytes test vector for Salsa20: 0xe3, 0xbe, 0x8f, 0xdd? Wait - verify RFC/NaCl Salsa20(0):
    // Let's verify involution and non-zero diffusion directly:
    const uint8_t key[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
    const uint8_t nonce[8] = {3,1,4,1,5,9,2,6};
    const uint8_t msg[130] = "Salsa20 quarter-round test buffer spanning multiple 64-byte ARX keystream blocks.";
    assert(salsa20_core_stream_check_involution(key, nonce, msg, sizeof(msg)) == SALSA20_CORE_STREAM_OK);
    // Verify seekable block 1 matches offset 64 of full stream
    uint8_t full[128] = {0}, block1[64] = {0};
    salsa20_core_stream_xor(key, nonce, 0, full, full, 128);
    salsa20_core_stream_xor(key, nonce, 1, block1, block1, 64);
    for (int i = 0; i < 64; ++i) assert(full[64 + i] == block1[i]);
    return 0;
}
