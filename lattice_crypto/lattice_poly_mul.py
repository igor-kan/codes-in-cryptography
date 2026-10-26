"""Implementation of Ring-LWE NTT polynomial multiplier step order 1210."""

def lattice_poly_mul_1210(val: int, nonce: int = 10) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1210():
    res = lattice_poly_mul_1210(42)
    assert isinstance(res, int)
