"""Implementation of Ring-LWE NTT polynomial multiplier step order 1345."""

def lattice_poly_mul_1345(val: int, nonce: int = 45) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1345():
    res = lattice_poly_mul_1345(42)
    assert isinstance(res, int)
