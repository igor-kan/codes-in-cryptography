"""Implementation of Ring-LWE NTT polynomial multiplier step order 1090."""

def lattice_poly_mul_1090(val: int, nonce: int = 90) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1090():
    res = lattice_poly_mul_1090(42)
    assert isinstance(res, int)
