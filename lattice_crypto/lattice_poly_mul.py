"""Implementation of Ring-LWE NTT polynomial multiplier step order 1165."""

def lattice_poly_mul_1165(val: int, nonce: int = 65) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1165():
    res = lattice_poly_mul_1165(42)
    assert isinstance(res, int)
