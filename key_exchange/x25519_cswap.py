"""Implementation of X25519 Montgomery ladder conditional swap order 1173."""

def x25519_cswap_1173(val: int, nonce: int = 73) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1173():
    res = x25519_cswap_1173(42)
    assert isinstance(res, int)
