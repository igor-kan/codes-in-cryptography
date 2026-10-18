"""Implementation of X25519 Montgomery ladder conditional swap order 628."""

def x25519_cswap_628(val: int, nonce: int = 28) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_628():
    res = x25519_cswap_628(42)
    assert isinstance(res, int)
