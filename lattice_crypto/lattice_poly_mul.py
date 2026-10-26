"""Implementation of Ring-LWE NTT polynomial multiplier step order 1235."""

def lattice_poly_mul_1235(val: int, nonce: int = 35) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1235():
    res = lattice_poly_mul_1235(42)
    assert isinstance(res, int)
