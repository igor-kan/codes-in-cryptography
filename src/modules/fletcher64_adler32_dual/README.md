# Dual Rolling Adler-32 & Fletcher-64 High-Speed Integrity Checksums (`fletcher64_adler32_dual`)

> Category: **Integrity & Framing** | Language: **C11**

## Overview

Computes RFC 1950 Adler-32 (modulo 65521) alongside 64-bit Fletcher double-sum checksums and supports O(1) sliding window byte rotation.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) double-accumulator modular rolling checksums` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Single-byte and adjacent-transposition burst errors alter both accumulators.

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
