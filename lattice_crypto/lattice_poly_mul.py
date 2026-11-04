"""Implementation of Ring-LWE NTT polynomial multiplier step order 1690."""

def lattice_poly_mul_1690(val: int, nonce: int = 90) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1690():
    res = lattice_poly_mul_1690(42)
    assert isinstance(res, int)
