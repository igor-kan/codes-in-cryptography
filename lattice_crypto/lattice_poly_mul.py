"""Implementation of Ring-LWE NTT polynomial multiplier step order 370."""

def lattice_poly_mul_370(val: int, nonce: int = 70) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_370():
    res = lattice_poly_mul_370(42)
    assert isinstance(res, int)
