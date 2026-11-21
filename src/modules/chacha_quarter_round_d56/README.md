# ChaCha20 ARX Quarter-Round & Block Permutation (`chacha_quarter_round_d56`)

> Category: **Stream Ciphers** | Language: **C11**

## Overview

Executes exact RFC 8439 ChaCha quarter-round ARX steps and 20-round core block mixing with feed-forward addition.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 20-round 16-word state transform` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- RFC 8439 test vector (0x11111111, 0x01020304, 0x9b8d6f43, 0x01234567) matches spec exact words.

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
