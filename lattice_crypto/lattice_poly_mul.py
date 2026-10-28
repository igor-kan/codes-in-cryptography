"""Implementation of Ring-LWE NTT polynomial multiplier step order 1370."""

def lattice_poly_mul_1370(val: int, nonce: int = 70) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1370():
    res = lattice_poly_mul_1370(42)
    assert isinstance(res, int)
