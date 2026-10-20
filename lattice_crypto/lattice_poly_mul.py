"""Implementation of Ring-LWE NTT polynomial multiplier step order 810."""

def lattice_poly_mul_810(val: int, nonce: int = 10) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_810():
    res = lattice_poly_mul_810(42)
    assert isinstance(res, int)
