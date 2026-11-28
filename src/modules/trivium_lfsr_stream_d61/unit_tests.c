#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(trivium_lfsr_stream_d61_validate_len(1) == TRIVIUM_LFSR_STREAM_D61_OK);
    uint8_t key[10], iv[10];
    memset(key, 0, sizeof(key));
    memset(iv, 0, sizeof(iv));
    trivium_state_d61_t a, b;
    trivium_init_d61(&a, key, iv);
    trivium_init_d61(&b, key, iv);
    uint64_t w1 = trivium_word_d61(&a);
    uint64_t w2 = trivium_word_d61(&b);
    assert(w1 == w2);
    assert(w1 != 0ULL);
    assert(trivium_lfsr_stream_d61_verify_guard(true) == TRIVIUM_LFSR_STREAM_D61_OK);
    return 0;
}
