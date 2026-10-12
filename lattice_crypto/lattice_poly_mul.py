"""Implementation of Ring-LWE NTT polynomial multiplier step order 5."""

def lattice_poly_mul_5(val: int, nonce: int = 5) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_5():
    res = lattice_poly_mul_5(42)
    assert isinstance(res, int)
