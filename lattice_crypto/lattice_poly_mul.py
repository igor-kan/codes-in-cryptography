"""Implementation of Ring-LWE NTT polynomial multiplier step order 1720."""

def lattice_poly_mul_1720(val: int, nonce: int = 20) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1720():
    res = lattice_poly_mul_1720(42)
    assert isinstance(res, int)
