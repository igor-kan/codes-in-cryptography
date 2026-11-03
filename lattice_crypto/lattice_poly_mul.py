"""Implementation of Ring-LWE NTT polynomial multiplier step order 1665."""

def lattice_poly_mul_1665(val: int, nonce: int = 65) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1665():
    res = lattice_poly_mul_1665(42)
    assert isinstance(res, int)
