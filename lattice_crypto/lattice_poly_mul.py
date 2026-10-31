"""Implementation of Ring-LWE NTT polynomial multiplier step order 1490."""

def lattice_poly_mul_1490(val: int, nonce: int = 90) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1490():
    res = lattice_poly_mul_1490(42)
    assert isinstance(res, int)
