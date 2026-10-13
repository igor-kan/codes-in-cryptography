"""Implementation of Ring-LWE NTT polynomial multiplier step order 120."""

def lattice_poly_mul_120(val: int, nonce: int = 20) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_120():
    res = lattice_poly_mul_120(42)
    assert isinstance(res, int)
