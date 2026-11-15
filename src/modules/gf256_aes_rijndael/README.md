# Rijndael GF(2^8) Branchless Field Arithmetic, S-Box & MixColumns (`gf256_aes_rijndael`)

> Category: **Finite Field Cryptography** | Language: **C11**

## Overview

Implements branchless constant-time GF(2^8) multiplication modulo irreducible polynomial x^8 + x^4 + x^3 + x + 1 (0x11B), multiplicative inverse via Frobenius-chain a^254, AES affine SubBytes, and MixColumns/InvMixColumns.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) constant-time` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Constant-time multiplication uses no secret-dependent branches or S-box table indexing.
- a * inv(a) == 1 in GF(2^8) for all nonzero bytes a in [1..255].
- InvMixColumns(MixColumns(col)) == col holds algebraically across all 32-bit columns.

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
