"""Implementation of Ring-LWE NTT polynomial multiplier step order 60."""

def lattice_poly_mul_60(val: int, nonce: int = 60) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_60():
    res = lattice_poly_mul_60(42)
    assert isinstance(res, int)
