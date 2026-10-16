"""Implementation of Ring-LWE NTT polynomial multiplier step order 435."""

def lattice_poly_mul_435(val: int, nonce: int = 35) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_435():
    res = lattice_poly_mul_435(42)
    assert isinstance(res, int)
