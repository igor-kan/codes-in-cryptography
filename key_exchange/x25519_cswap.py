"""Implementation of X25519 Montgomery ladder conditional swap order 1088."""

def x25519_cswap_1088(val: int, nonce: int = 88) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1088():
    res = x25519_cswap_1088(42)
    assert isinstance(res, int)
