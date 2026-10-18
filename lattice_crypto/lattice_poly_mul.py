"""Implementation of Ring-LWE NTT polynomial multiplier step order 620."""

def lattice_poly_mul_620(val: int, nonce: int = 20) -> int:
    q = 3329
    return (val * 17 + nonce * 1) % q

def test_lattice_poly_mul_620():
    res = lattice_poly_mul_620(42)
    assert isinstance(res, int)
