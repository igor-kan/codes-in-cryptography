# XTEA 64-Round Block Cipher Encipher/Decipher (`xtea_feistel_block_d56`)

> Category: **Symmetric Block Ciphers** | Language: **C11**

## Overview

Implements Needham-Wheeler-Needham Extended Tiny Encryption Algorithm (XTEA) 64-bit block encryption and exact inverse key schedule decryption.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 32-cycle Feistel network` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Decryption strictly recovers the exact 64-bit plaintext for any 128-bit key.

## Module Architecture

| File | Lifecycle Role |
| :--- | :--- |
| `types.h` | Stage 01 |
| `errors.h` | Stage 02 |
| `interface.h` | Stage 03 |
| `core.c` | Stage 04 |
| `validation.c` | Stage 05 |
| `fast_path.c` | Stage 06 |
| `concurrent.c` | Stage 07 |
| `invariants.c` | Stage 08 |
| `unit_tests.c` | Stage 09 |
| `property_tests.c` | Stage 10 |
| `benchmark.c` | Stage 11 |
| `README.md` | Stage 12 |

## Verification & Execution Example

```text
gcc -std=c11 -O2 -Wall -Wextra -Werror -pthread core.c validation.c fast_path.c concurrent.c invariants.c unit_tests.c -lm -o test_bin && ./test_bin
```

---
© 2026 Igor Kan
