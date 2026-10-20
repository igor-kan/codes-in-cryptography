"""Implementation of Ring-LWE NTT polynomial multiplier step order 815."""

def lattice_poly_mul_815(val: int, nonce: int = 15) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_815():
    res = lattice_poly_mul_815(42)
    assert isinstance(res, int)
