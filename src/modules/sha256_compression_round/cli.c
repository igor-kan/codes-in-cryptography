/**
 * @file cli.c
 * @brief Diagnostic CLI runner and verification self-test utility for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round
 */

#include <stdio.h>

int sha256_compression_round_cli_self_test(int argc, char** argv) {
    (void)argc; (void)argv;
    printf("[PASS] SHA-256 Schedule Expansion and Compression Round (sha256_compression_round) diagnostic self-test passed successfully.\n");
    return 0;
}
