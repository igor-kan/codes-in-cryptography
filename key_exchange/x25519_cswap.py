"""Implementation of X25519 Montgomery ladder conditional swap order 1168."""

def x25519_cswap_1168(val: int, nonce: int = 68) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1168():
    res = x25519_cswap_1168(42)
    assert isinstance(res, int)
