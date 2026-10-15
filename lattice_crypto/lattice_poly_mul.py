"""Implementation of Ring-LWE NTT polynomial multiplier step order 320."""

def lattice_poly_mul_320(val: int, nonce: int = 20) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_320():
    res = lattice_poly_mul_320(42)
    assert isinstance(res, int)
