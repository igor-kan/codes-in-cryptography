# FIPS-197 AES-128 Key Expansion & Forward/Inverse Block Cipher (`aes128_fips197_cipher`)

> Category: **Symmetric Block Ciphers** | Language: **C11**

## Overview

Implements complete FIPS-197 AES-128 key schedule expansion (SubWord/RotWord/Rcon) and both forward encryption (SubBytes, ShiftRows, MixColumns) and inverse decryption.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) fixed 10-round block transform` |
| **Space Complexity** | `O(1) (176-byte expanded key schedule)` |

## Mathematical & Safety Invariants

- Exact match against NIST FIPS-197 Appendix B test vector (2b7e1516.. + 3243f6a8.. -> 3925841d..).
- decrypt(encrypt(block, rk), rk) == block for arbitrary random keys and blocks.

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
