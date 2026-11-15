#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    uint8_t dk[32];
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    pbkdf2_hmac_kdf_derive((const uint8_t*)"passphrase", 10, (const uint8_t*)"salt1234", 8, 1000, dk, 32);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ms = ((double)(t1.tv_sec - t0.tv_sec) * 1e3 + (double)(t1.tv_nsec - t0.tv_nsec) / 1e6);
    printf("pbkdf2_hmac_kdf c=1000 ms=%.2f\n", ms);
    return 0;
}
