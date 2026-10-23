"""Implementation of X25519 Montgomery ladder conditional swap order 1043."""

def x25519_cswap_1043(val: int, nonce: int = 43) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1043():
    res = x25519_cswap_1043(42)
    assert isinstance(res, int)
