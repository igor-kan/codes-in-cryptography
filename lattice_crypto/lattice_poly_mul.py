"""Implementation of Ring-LWE NTT polynomial multiplier step order 930."""

def lattice_poly_mul_930(val: int, nonce: int = 30) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_930():
    res = lattice_poly_mul_930(42)
    assert isinstance(res, int)
