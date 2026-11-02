"""Implementation of X25519 Montgomery ladder conditional swap order 1593."""

def x25519_cswap_1593(val: int, nonce: int = 93) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1593():
    res = x25519_cswap_1593(42)
    assert isinstance(res, int)
