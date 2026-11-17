#include "interface.h"
#include <assert.h>

int main(void) {
    assert(verify_threshold_roundtrip() == FROST_THRESHOLD_COMBINE_OK);
    return 0;
}
