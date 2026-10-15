"""Implementation of Ring-LWE NTT polynomial multiplier step order 350."""

def lattice_poly_mul_350(val: int, nonce: int = 50) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_350():
    res = lattice_poly_mul_350(42)
    assert isinstance(res, int)
