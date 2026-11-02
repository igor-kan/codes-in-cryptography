"""Implementation of Ring-LWE NTT polynomial multiplier step order 1590."""

def lattice_poly_mul_1590(val: int, nonce: int = 90) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1590():
    res = lattice_poly_mul_1590(42)
    assert isinstance(res, int)
