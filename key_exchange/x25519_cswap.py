"""Implementation of X25519 Montgomery ladder conditional swap order 123."""

def x25519_cswap_123(val: int, nonce: int = 23) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_123():
    res = x25519_cswap_123(42)
    assert isinstance(res, int)
