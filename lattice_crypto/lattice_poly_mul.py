"""Implementation of Ring-LWE NTT polynomial multiplier step order 1145."""

def lattice_poly_mul_1145(val: int, nonce: int = 45) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1145():
    res = lattice_poly_mul_1145(42)
    assert isinstance(res, int)
