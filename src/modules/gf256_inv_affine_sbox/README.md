# AES GF(2^8) Multiplicative Inverse & Affine S-Box Synthesizer (`gf256_inv_affine_sbox`)

> Category: **Finite-Field Cryptography** | Language: **C11**

## Overview

Generates the Rijndael AES S-Box purely algebraically via GF(2^8) multiplicative inversion modulo x^8 + x^4 + x^3 + x + 1 followed by the cyclic bit-affine transform + 0x63.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) GF(2^8) mod 0x11B inversion + 8-bit affine linear map` |
| **Space Complexity** | `O(256)` |

## Mathematical & Safety Invariants

- Synthesized S-box[0x00] == 0x63 and S-box[0x53] == 0xed (FIPS-197).

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
