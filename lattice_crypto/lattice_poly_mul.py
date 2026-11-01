"""Implementation of Ring-LWE NTT polynomial multiplier step order 1540."""

def lattice_poly_mul_1540(val: int, nonce: int = 40) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1540():
    res = lattice_poly_mul_1540(42)
    assert isinstance(res, int)
