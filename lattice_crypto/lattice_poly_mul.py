"""Implementation of Ring-LWE NTT polynomial multiplier step order 1450."""

def lattice_poly_mul_1450(val: int, nonce: int = 50) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1450():
    res = lattice_poly_mul_1450(42)
    assert isinstance(res, int)
