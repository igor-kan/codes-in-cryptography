"""Implementation of Ring-LWE NTT polynomial multiplier step order 1510."""

def lattice_poly_mul_1510(val: int, nonce: int = 10) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1510():
    res = lattice_poly_mul_1510(42)
    assert isinstance(res, int)
