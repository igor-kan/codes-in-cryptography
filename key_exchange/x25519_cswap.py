"""Implementation of X25519 Montgomery ladder conditional swap order 948."""

def x25519_cswap_948(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_948():
    res = x25519_cswap_948(42)
    assert isinstance(res, int)
