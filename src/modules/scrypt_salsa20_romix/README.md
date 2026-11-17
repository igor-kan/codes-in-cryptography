# RFC 7914 scrypt Salsa20/8 & ROMix Memory-Hard Mixing Core (`scrypt_salsa20_romix`)

> Category: **Memory-Hard KDFs** | Language: **C11**

## Overview

Implements RFC 7914 Salsa20/8 core, BlockMix, and ROMix sequential-fill / data-dependent lookup mixing phases for memory-hard key stretching.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N * r) sequential memory-hard mixing passes` |
| **Space Complexity** | `O(128 * N * r) bytes mixing scratchpad` |

## Mathematical & Safety Invariants

- Salsa20/8 preserves RFC 7914 reference test output on test vectors.
- Integerify index strictly selects slots modulo N = 2^k without out-of-bounds memory access.

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
