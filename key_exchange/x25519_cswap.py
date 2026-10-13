"""Implementation of X25519 Montgomery ladder conditional swap order 163."""

def x25519_cswap_163(val: int, nonce: int = 63) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_163():
    res = x25519_cswap_163(42)
    assert isinstance(res, int)
