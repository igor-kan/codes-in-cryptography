# Rabin Blum-Prime Quadratic Residue Trapdoor & CRT Inversion (`rabin_williams_sqrt_trap`)

> Category: **Public-Key Trapdoors** | Language: **C11**

## Overview

Computes the four modular square roots of m^2 mod (p*q) for Blum primes p, q = 3 (mod 4) via fast exponentiation (p+1)/4 and extended Euclidean CRT.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log^3 N) Blum exponentiation (p+1)/4 + Chinese Remainder Theorem` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- All four CRT roots square identically to ciphertext c = m^2 mod n.

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
