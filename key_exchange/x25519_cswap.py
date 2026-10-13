"""Implementation of X25519 Montgomery ladder conditional swap order 158."""

def x25519_cswap_158(val: int, nonce: int = 58) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_158():
    res = x25519_cswap_158(42)
    assert isinstance(res, int)
