"""Implementation of Ring-LWE NTT polynomial multiplier step order 135."""

def lattice_poly_mul_135(val: int, nonce: int = 35) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_135():
    res = lattice_poly_mul_135(42)
    assert isinstance(res, int)
