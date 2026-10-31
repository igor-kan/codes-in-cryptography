"""Implementation of X25519 Montgomery ladder conditional swap order 1493."""

def x25519_cswap_1493(val: int, nonce: int = 93) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1493():
    res = x25519_cswap_1493(42)
    assert isinstance(res, int)
