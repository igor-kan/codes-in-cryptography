# 8-Round ARX Balanced Feistel Bijection Permutation (`feistel_8round_d59`)

> Category: **Format-Preserving Cryptography** | Language: **C11**

## Overview

Applies 8 keyed ARX Feistel rounds over 64-bit blocks with exact reverse round subtraction decryption cleanly.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 8-round involution reverse` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Encrypt followed by decrypt restores original 64-bit word identically.

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
