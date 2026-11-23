# Classic 32-Cycle TEA 64-Bit Block Cipher (`tea_classic_64_d58`)

> Category: **Symmetric Ciphers** | Language: **C11**

## Overview

Implements the original Wheeler-Needham Tiny Encryption Algorithm (TEA) with golden-ratio round constant 0x9E3779B9 and exact reverse decryption.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 64-round Feistel schedule` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Encrypting then decrypting recovers original 64-bit word pair cleanly.

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
