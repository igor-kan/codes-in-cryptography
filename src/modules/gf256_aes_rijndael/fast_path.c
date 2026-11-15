#include "interface.h"
void gf256_aes_rijndael_mix_state_fast(uint8_t state[16]) {
    for (int col = 0; col < 4; ++col) gf256_aes_rijndael_mix_column(state + col * 4);
}
