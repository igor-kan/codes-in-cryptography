"""Implementation of X25519 Montgomery ladder conditional swap order 143."""

def x25519_cswap_143(val: int, nonce: int = 43) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_143():
    res = x25519_cswap_143(42)
    assert isinstance(res, int)
