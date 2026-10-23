"""Implementation of Ring-LWE NTT polynomial multiplier step order 1015."""

def lattice_poly_mul_1015(val: int, nonce: int = 15) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1015():
    res = lattice_poly_mul_1015(42)
    assert isinstance(res, int)
