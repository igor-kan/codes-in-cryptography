# MuSig2 Two-Nonce Linear Aggregation & Binding Factor (`schnorr_musig2_nonce_agg`)

> Category: **Multi-Signatures** | Language: **C11**

## Overview

Combines N pairs of public nonces (R_{i,1}, R_{i,2}) into an aggregated Schnorr nonce R = R_1 * R_2^b mod p using deterministic transcript binding coefficient b.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) multi-signer nonce pair binding and group combination` |
| **Space Complexity** | `O(N) signer nonce pairs` |

## Mathematical & Safety Invariants

- Aggregated nonce R equals g^(sum(r_{i,1} + b * r_{i,2})) mod p.
- Rogue-key cancellation is prevented by binding b to all public nonces.

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
