#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(gimli_24round_spbox_perm_validate_len(1) == GIMLI_24ROUND_SPBOX_PERM_OK);
    gimli_state_t st, st2;
    for (uint32_t i = 0; i < 12; ++i) st.s[i] = i * i * i + i * 0x9e3779b9U;
    st2 = st;
    gimli_permute(&st);
    gimli_permute(&st2);
    assert(st.s[0] != 0U && memcmp(&st, &st2, sizeof(st)) == 0);
    assert(gimli_24round_spbox_perm_verify_guard(true) == GIMLI_24ROUND_SPBOX_PERM_OK);
    return 0;
}
