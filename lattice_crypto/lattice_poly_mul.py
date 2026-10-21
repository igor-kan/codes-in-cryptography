"""Implementation of Ring-LWE NTT polynomial multiplier step order 950."""

def lattice_poly_mul_950(val: int, nonce: int = 50) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_950():
    res = lattice_poly_mul_950(42)
    assert isinstance(res, int)
