#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(xtea_feistel_block_d56_validate_len(1) == XTEA_FEISTEL_BLOCK_D56_OK);
    uint32_t key[4] = {0x01020304u, 0x05060708u, 0x090a0b0cu, 0x0d0e0f10u};
    uint32_t blk[2] = {0xdeadbeefu, 0xcafebabeu};
    xtea_encrypt_block(blk, key);
    assert(blk[0] != 0xdeadbeefu);
    xtea_decrypt_block(blk, key);
    assert(blk[0] == 0xdeadbeefu && blk[1] == 0xcafebabeu);
    assert(xtea_feistel_block_d56_verify_guard(true) == XTEA_FEISTEL_BLOCK_D56_OK);
    return 0;
}
