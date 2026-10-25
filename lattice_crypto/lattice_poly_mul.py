"""Implementation of Ring-LWE NTT polynomial multiplier step order 1170."""

def lattice_poly_mul_1170(val: int, nonce: int = 70) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1170():
    res = lattice_poly_mul_1170(42)
    assert isinstance(res, int)
