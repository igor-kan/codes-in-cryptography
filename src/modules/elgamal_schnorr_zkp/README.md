# Fiat-Shamir Non-Interactive Schnorr Zero-Knowledge Proof of Knowledge (`elgamal_schnorr_zkp`)

> Category: **Zero-Knowledge Proofs** | Language: **C11**

## Overview

Constructs and verifies non-interactive Schnorr zero-knowledge proofs (R, s) proving knowledge of secret key x such that g^x = pk mod p.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log P) commitment g^k, Fiat-Shamir challenge, and verification check` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Verification equation g^s == R * pk^c mod p holds for valid witness without revealing x.

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
