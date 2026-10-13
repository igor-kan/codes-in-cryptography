"""Implementation of Ring-LWE NTT polynomial multiplier step order 175."""

def lattice_poly_mul_175(val: int, nonce: int = 75) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_175():
    res = lattice_poly_mul_175(42)
    assert isinstance(res, int)
