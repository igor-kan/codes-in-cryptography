"""Implementation of X25519 Montgomery ladder conditional swap order 703."""

def x25519_cswap_703(val: int, nonce: int = 3) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_703():
    res = x25519_cswap_703(42)
    assert isinstance(res, int)
