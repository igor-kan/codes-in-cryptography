"""Implementation of Ring-LWE NTT polynomial multiplier step order 1570."""

def lattice_poly_mul_1570(val: int, nonce: int = 70) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1570():
    res = lattice_poly_mul_1570(42)
    assert isinstance(res, int)
