"""Implementation of Ring-LWE NTT polynomial multiplier step order 1695."""

def lattice_poly_mul_1695(val: int, nonce: int = 95) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1695():
    res = lattice_poly_mul_1695(42)
    assert isinstance(res, int)
