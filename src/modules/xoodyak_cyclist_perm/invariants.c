#include "interface.h"
#include <string.h>

xoodyak_cyclist_perm_err_t xoodoo_verify_avalanche(void) {
    xoodoo_state_t a, b;
    memset(&a, 0, sizeof(a));
    memset(&b, 0, sizeof(b));
    a.lanes[0] = 1U;
    b.lanes[0] = 3U;
    xoodoo_permute_12(&a);
    xoodoo_permute_12(&b);
    int diff_bits = 0;
    for (int i = 0; i < 12; ++i) diff_bits += __builtin_popcount(a.lanes[i] ^ b.lanes[i]);
    return diff_bits >= 120 ? XOODYAK_CYCLIST_PERM_OK : XOODYAK_CYCLIST_PERM_ERR_INVARIANT;
}
