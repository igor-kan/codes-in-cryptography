# 4-Round Keyed Luby-Rackoff PRP Feistel Block Cipher (`feistel_luby_rackoff_c11`)

> Category: **Symmetric Block Ciphers** | Language: **C11**

## Overview

Implements an invertible 4-round balanced 64-bit Luby-Rackoff Feistel block permutation with non-linear keyed PRF mixing.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(R) balanced 32-bit F-function Feistel rounds` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Decryption exactly inverts encryption for arbitrary 64-bit plaintexts and 128-bit keys.

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
