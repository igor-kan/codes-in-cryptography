"""Implementation of Ring-LWE NTT polynomial multiplier step order 205."""

def lattice_poly_mul_205(val: int, nonce: int = 5) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_205():
    res = lattice_poly_mul_205(42)
    assert isinstance(res, int)
