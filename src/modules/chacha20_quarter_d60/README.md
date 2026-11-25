# RFC 8439 ChaCha20 Block Keystream Permutation (`chacha20_quarter_d60`)

> Category: **Stream Ciphers** | Language: **C11**

## Overview

Executes all 10 column-and-diagonal double rounds of ChaCha20 with expand-32-byte-k constant and feed-forward addition.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 20-round ARX 4x4 state permutation` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Matches RFC 8439 Section 2.3.2 test vector output word 0 and word 15.

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
