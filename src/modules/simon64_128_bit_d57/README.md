# Simon 64/128 Hardware-Bitwise Block Cipher (`simon64_128_bit_d57`)

> Category: **Lightweight Cryptography** | Language: **C11**

## Overview

Implements NSA Simon-64/128 44-round AND-shift-XOR Feistel permutation and Z_3 constant schedule with exact inverse decryption.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 44-round Feistel schedule` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Official NSA Simon-64/128 test vector encrypts and decrypts cleanly.

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
