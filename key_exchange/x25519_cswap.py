"""Implementation of X25519 Montgomery ladder conditional swap order 1468."""

def x25519_cswap_1468(val: int, nonce: int = 68) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1468():
    res = x25519_cswap_1468(42)
    assert isinstance(res, int)
