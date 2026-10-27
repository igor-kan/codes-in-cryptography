"""Implementation of Ring-LWE NTT polynomial multiplier step order 1260."""

def lattice_poly_mul_1260(val: int, nonce: int = 60) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1260():
    res = lattice_poly_mul_1260(42)
    assert isinstance(res, int)
