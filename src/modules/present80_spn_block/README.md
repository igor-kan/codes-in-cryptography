# PRESENT-80 ISO/IEC 29192 SPN Block Cipher (`present80_spn_block`)

> Category: **Lightweight Block Ciphers** | Language: **C11**

## Overview

Implements the ultra-lightweight 64-bit PRESENT-80 SPN cipher with its 4-bit S-box, inverse S-box, 64-bit bit-permutation pLayer, and 80-bit key schedule.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 31-round Substitution-Permutation Network` |
| **Space Complexity** | `32 uint64_t round keys` |

## Mathematical & Safety Invariants

- PRESENT-80 reference test vector (0x0000000000000000 under all-zero key) matches ISO/IEC 29192 output 0x5579C1387B228445.
- Decryption recovers exact plaintext block.

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
