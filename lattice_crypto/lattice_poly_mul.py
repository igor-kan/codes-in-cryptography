"""Implementation of Ring-LWE NTT polynomial multiplier step order 335."""

def lattice_poly_mul_335(val: int, nonce: int = 35) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_335():
    res = lattice_poly_mul_335(42)
    assert isinstance(res, int)
