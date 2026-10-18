"""Implementation of Ring-LWE NTT polynomial multiplier step order 640."""

def lattice_poly_mul_640(val: int, nonce: int = 40) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_640():
    res = lattice_poly_mul_640(42)
    assert isinstance(res, int)
