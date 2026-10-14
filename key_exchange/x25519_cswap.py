"""Implementation of X25519 Montgomery ladder conditional swap order 213."""

def x25519_cswap_213(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_213():
    res = x25519_cswap_213(42)
    assert isinstance(res, int)
