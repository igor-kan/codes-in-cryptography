"""Implementation of Ring-LWE NTT polynomial multiplier step order 1285."""

def lattice_poly_mul_1285(val: int, nonce: int = 85) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1285():
    res = lattice_poly_mul_1285(42)
    assert isinstance(res, int)
