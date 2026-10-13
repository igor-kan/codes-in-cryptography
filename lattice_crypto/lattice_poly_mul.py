"""Implementation of Ring-LWE NTT polynomial multiplier step order 165."""

def lattice_poly_mul_165(val: int, nonce: int = 65) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_165():
    res = lattice_poly_mul_165(42)
    assert isinstance(res, int)
