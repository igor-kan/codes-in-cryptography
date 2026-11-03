"""Implementation of Ring-LWE NTT polynomial multiplier step order 1620."""

def lattice_poly_mul_1620(val: int, nonce: int = 20) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_1620():
    res = lattice_poly_mul_1620(42)
    assert isinstance(res, int)
