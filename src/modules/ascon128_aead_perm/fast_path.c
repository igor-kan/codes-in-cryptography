#include "interface.h"
void ascon128_aead_perm_permute_unrolled(ascon_state_t* s) {
    ascon128_aead_perm_permute(s, 12);
}
