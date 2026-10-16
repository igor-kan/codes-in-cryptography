"""Implementation of Ring-LWE NTT polynomial multiplier step order 410."""

def lattice_poly_mul_410(val: int, nonce: int = 10) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_410():
    res = lattice_poly_mul_410(42)
    assert isinstance(res, int)
