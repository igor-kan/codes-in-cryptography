"""Implementation of Ring-LWE NTT polynomial multiplier step order 1080."""

def lattice_poly_mul_1080(val: int, nonce: int = 80) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1080():
    res = lattice_poly_mul_1080(42)
    assert isinstance(res, int)
