# Chaskey-12 Lightweight 128-Bit ARX Message Authentication Code (`chaskey_mac_128`)

> Category: **Message Authentication Codes** | Language: **C11**

## Overview

Implements the ISO/IEC 29192-6 Chaskey-12 lightweight 128-bit ARX MAC with GF(2^128) subkey doubling (K1, K2), ISO padding, and constant-time tag verification.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) 16-byte block ARX permutation` |
| **Space Complexity** | `O(1) stack state` |

## Mathematical & Safety Invariants

- Flipping any bit in message or key flips ~50% of the 128-bit authentication tag.
- Subkey K1 != K2 != K whenever key is non-zero.

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
