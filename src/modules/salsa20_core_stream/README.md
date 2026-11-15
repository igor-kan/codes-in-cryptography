# Salsa20/20 Stream Cipher Core & Keystream XOR Engine (`salsa20_core_stream`)

> Category: **Stream Ciphers** | Language: **C11**

## Overview

Implements Daniel J. Bernstein's Salsa20/20 512-bit ARX matrix core with column/row quarter-rounds (rotations 7, 9, 13, 18) and seekable counter keystream encryption.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- XOR stream cipher is self-inverse: apply_xor(key, nonce, ctr, apply_xor(key, nonce, ctr, pt)) == pt.
- Block counter increments deterministically without cross-block dependency.

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
