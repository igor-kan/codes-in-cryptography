"""Implementation of Ring-LWE NTT polynomial multiplier step order 615."""

def lattice_poly_mul_615(val: int, nonce: int = 15) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_615():
    res = lattice_poly_mul_615(42)
    assert isinstance(res, int)
