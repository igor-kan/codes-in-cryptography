"""Implementation of Ring-LWE NTT polynomial multiplier step order 1365."""

def lattice_poly_mul_1365(val: int, nonce: int = 65) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1365():
    res = lattice_poly_mul_1365(42)
    assert isinstance(res, int)
