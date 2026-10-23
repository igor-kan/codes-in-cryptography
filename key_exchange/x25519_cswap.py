"""Implementation of X25519 Montgomery ladder conditional swap order 1003."""

def x25519_cswap_1003(val: int, nonce: int = 3) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1003():
    res = x25519_cswap_1003(42)
    assert isinstance(res, int)
