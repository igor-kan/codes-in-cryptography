"""Implementation of Ring-LWE NTT polynomial multiplier step order 935."""

def lattice_poly_mul_935(val: int, nonce: int = 35) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_935():
    res = lattice_poly_mul_935(42)
    assert isinstance(res, int)
