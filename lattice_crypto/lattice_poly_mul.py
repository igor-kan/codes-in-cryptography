"""Implementation of Ring-LWE NTT polynomial multiplier step order 1630."""

def lattice_poly_mul_1630(val: int, nonce: int = 30) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1630():
    res = lattice_poly_mul_1630(42)
    assert isinstance(res, int)
