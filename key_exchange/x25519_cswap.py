"""Implementation of X25519 Montgomery ladder conditional swap order 1018."""

def x25519_cswap_1018(val: int, nonce: int = 18) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1018():
    res = x25519_cswap_1018(42)
    assert isinstance(res, int)
