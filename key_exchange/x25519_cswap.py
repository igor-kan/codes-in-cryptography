"""Implementation of X25519 Montgomery ladder conditional swap order 303."""

def x25519_cswap_303(val: int, nonce: int = 3) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_303():
    res = x25519_cswap_303(42)
    assert isinstance(res, int)
