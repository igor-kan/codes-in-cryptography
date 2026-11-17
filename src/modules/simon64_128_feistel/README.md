# SIMON-64/128 Lightweight ARX Feistel Block Cipher (`simon64_128_feistel`)

> Category: **Block Ciphers** | Language: **C11**

## Overview

Implements NSA's SIMON-64/128 block cipher key expansion and 44-round invertible Feistel encryption and decryption matching official z3 sequence constants.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 44-round 64-bit Feistel network` |
| **Space Complexity** | `44 uint32_t expanded round keys` |

## Mathematical & Safety Invariants

- decrypt(key, encrypt(key, pt)) == pt for every 64-bit block and 128-bit key.

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
