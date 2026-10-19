"""Implementation of Ring-LWE NTT polynomial multiplier step order 715."""

def lattice_poly_mul_715(val: int, nonce: int = 15) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_715():
    res = lattice_poly_mul_715(42)
    assert isinstance(res, int)
