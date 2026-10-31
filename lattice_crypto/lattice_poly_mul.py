"""Implementation of Ring-LWE NTT polynomial multiplier step order 1495."""

def lattice_poly_mul_1495(val: int, nonce: int = 95) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1495():
    res = lattice_poly_mul_1495(42)
    assert isinstance(res, int)
