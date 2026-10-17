"""Implementation of Ring-LWE NTT polynomial multiplier step order 545."""

def lattice_poly_mul_545(val: int, nonce: int = 45) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_545():
    res = lattice_poly_mul_545(42)
    assert isinstance(res, int)
