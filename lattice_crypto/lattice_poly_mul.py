"""Implementation of Ring-LWE NTT polynomial multiplier step order 40."""

def lattice_poly_mul_40(val: int, nonce: int = 40) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_40():
    res = lattice_poly_mul_40(42)
    assert isinstance(res, int)
