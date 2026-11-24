# Algebraic AES SubBytes GF(2^8) Inverse + Affine S-Box (`aes_subbytes_sbox_d59`)

> Category: **Block Ciphers** | Language: **C11**

## Overview

Computes exact Rijndael S-Box bytes from GF(2^8) inverse a^254 followed by bit-matrix affine transform modulo 0x63 cleanly verifying NIST FIPS-197 values.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) constant-step bit evaluation` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Algebraic SubBytes matches NIST vectors S(0x00)=0x63, S(0x53)=0xED.

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
