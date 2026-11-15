# XTEA 64-Round Feistel Block Cipher & CBC-MAC Authenticator (`xtea_cbc_mac`)

> Category: **Block Ciphers & MAC** | Language: **C11**

## Overview

Implements Needham-Wheeler eXtended TEA (XTEA) 64-round 64-bit block encryption/decryption using golden-ratio delta 0x9E3779B9 and CBC-MAC authentication over multi-block messages.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- decrypt_block(key, encrypt_block(key, v)) == v for all 64-bit plaintext blocks and 128-bit keys.
- CBC-MAC output depends non-linearly on every bit of every prior block.

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
