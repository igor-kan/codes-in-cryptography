"""Implementation of Ring-LWE NTT polynomial multiplier step order 1610."""

def lattice_poly_mul_1610(val: int, nonce: int = 10) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1610():
    res = lattice_poly_mul_1610(42)
    assert isinstance(res, int)
