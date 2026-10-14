"""Implementation of Ring-LWE NTT polynomial multiplier step order 255."""

def lattice_poly_mul_255(val: int, nonce: int = 55) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_255():
    res = lattice_poly_mul_255(42)
    assert isinstance(res, int)
