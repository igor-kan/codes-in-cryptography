# Salsa20 ARX Quarter-Round & Core 20-Round Block (`salsa20_qr_core_d59`)

> Category: **Stream Ciphers** | Language: **C11**

## Overview

Implements Bernstein's Salsa20 exact quarterround ARX transform and 20-round double-round block function matching specification test vectors.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 20-round 16-word permutation` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Official Salsa20 quarterround test vector outputs exact specification words.

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
