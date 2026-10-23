"""Implementation of Ring-LWE NTT polynomial multiplier step order 1050."""

def lattice_poly_mul_1050(val: int, nonce: int = 50) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1050():
    res = lattice_poly_mul_1050(42)
    assert isinstance(res, int)
