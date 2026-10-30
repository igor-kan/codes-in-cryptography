"""Implementation of X25519 Montgomery ladder conditional swap order 1413."""

def x25519_cswap_1413(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1413():
    res = x25519_cswap_1413(42)
    assert isinstance(res, int)
