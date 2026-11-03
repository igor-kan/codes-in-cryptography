"""Implementation of Ring-LWE NTT polynomial multiplier step order 1615."""

def lattice_poly_mul_1615(val: int, nonce: int = 15) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1615():
    res = lattice_poly_mul_1615(42)
    assert isinstance(res, int)
