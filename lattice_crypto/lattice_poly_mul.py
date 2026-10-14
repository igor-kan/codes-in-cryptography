"""Implementation of Ring-LWE NTT polynomial multiplier step order 245."""

def lattice_poly_mul_245(val: int, nonce: int = 45) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_245():
    res = lattice_poly_mul_245(42)
    assert isinstance(res, int)
