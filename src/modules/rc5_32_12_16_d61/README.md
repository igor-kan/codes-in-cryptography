# RC5-32/12/16 Word-Oriented Rotating Block Cipher (`rc5_32_12_16_d61`)

> Category: **Block Ciphers** | Language: **C11**

## Overview

Implements RC5-32/12/16 with the golden-ratio key schedule, data-dependent left rotations, and an exact inverse decryption path.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 12 data-dependent rotation rounds per 64-bit block` |
| **Space Complexity** | `O(1) 26-word expanded key` |

## Mathematical & Safety Invariants

- The all-zero key and block produce the canonical 21A5DBEE/154B8F6D block.

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
