"""Implementation of X25519 Montgomery ladder conditional swap order 1258."""

def x25519_cswap_1258(val: int, nonce: int = 58) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1258():
    res = x25519_cswap_1258(42)
    assert isinstance(res, int)
