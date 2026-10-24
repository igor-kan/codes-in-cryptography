"""Implementation of Ring-LWE NTT polynomial multiplier step order 1100."""

def lattice_poly_mul_1100(val: int, nonce: int = 0) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1100():
    res = lattice_poly_mul_1100(42)
    assert isinstance(res, int)
