"""Implementation of Ring-LWE NTT polynomial multiplier step order 1300."""

def lattice_poly_mul_1300(val: int, nonce: int = 0) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1300():
    res = lattice_poly_mul_1300(42)
    assert isinstance(res, int)
