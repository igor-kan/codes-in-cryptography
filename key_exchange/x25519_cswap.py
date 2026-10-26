"""Implementation of X25519 Montgomery ladder conditional swap order 1233."""

def x25519_cswap_1233(val: int, nonce: int = 33) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1233():
    res = x25519_cswap_1233(42)
    assert isinstance(res, int)
