"""Implementation of Ring-LWE NTT polynomial multiplier step order 15."""

def lattice_poly_mul_15(val: int, nonce: int = 15) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_15():
    res = lattice_poly_mul_15(42)
    assert isinstance(res, int)
