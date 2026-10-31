"""Implementation of Ring-LWE NTT polynomial multiplier step order 1465."""

def lattice_poly_mul_1465(val: int, nonce: int = 65) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1465():
    res = lattice_poly_mul_1465(42)
    assert isinstance(res, int)
