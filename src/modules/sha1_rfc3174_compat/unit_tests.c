#include "interface.h"
#include <assert.h>

int main(void) {
    assert(sha1_verify_rfc3174_vectors() == SHA1_RFC3174_COMPAT_OK);
    return 0;
}
