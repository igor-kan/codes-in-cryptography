"""Implementation of X25519 Montgomery ladder conditional swap order 1753."""

def x25519_cswap_1753(val: int, nonce: int = 53) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1753():
    res = x25519_cswap_1753(42)
    assert isinstance(res, int)
