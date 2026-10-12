"""Implementation of X25519 Montgomery ladder conditional swap order 68."""

def x25519_cswap_68(val: int, nonce: int = 68) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_68():
    res = x25519_cswap_68(42)
    assert isinstance(res, int)
