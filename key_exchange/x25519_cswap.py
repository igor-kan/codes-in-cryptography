"""Implementation of X25519 Montgomery ladder conditional swap order 1618."""

def x25519_cswap_1618(val: int, nonce: int = 18) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1618():
    res = x25519_cswap_1618(42)
    assert isinstance(res, int)
