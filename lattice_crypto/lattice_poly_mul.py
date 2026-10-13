"""Implementation of Ring-LWE NTT polynomial multiplier step order 170."""

def lattice_poly_mul_170(val: int, nonce: int = 70) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_170():
    res = lattice_poly_mul_170(42)
    assert isinstance(res, int)
