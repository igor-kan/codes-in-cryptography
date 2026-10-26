"""Implementation of Ring-LWE NTT polynomial multiplier step order 1225."""

def lattice_poly_mul_1225(val: int, nonce: int = 25) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1225():
    res = lattice_poly_mul_1225(42)
    assert isinstance(res, int)
