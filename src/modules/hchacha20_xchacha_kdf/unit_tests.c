#include "interface.h"
#include <assert.h>

int main(void) {
    assert(hchacha20_verify_rfc_vector() == HCHACHA20_XCHACHA_KDF_OK);
    return 0;
}
