#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(blakley_hyperplane_share_validate_len(1) == BLAKLEY_HYPERPLANE_SHARE_OK);
    hyperplane_share_t h1 = blak_deal_share(987654ULL, 444555ULL, 3ULL, 5ULL);
    hyperplane_share_t h2 = blak_deal_share(987654ULL, 444555ULL, 7ULL, 11ULL);
    hyperplane_share_t h3 = blak_deal_share(987654ULL, 444555ULL, 13ULL, 2ULL);
    assert(blak_recover_secret(h1, h2) == 987654ULL);
    assert(blak_recover_secret(h2, h3) == 987654ULL);
    assert(blakley_hyperplane_share_verify_guard(true) == BLAKLEY_HYPERPLANE_SHARE_OK);
    return 0;
}
