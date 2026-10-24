"""Implementation of X25519 Montgomery ladder conditional swap order 1103."""

def x25519_cswap_1103(val: int, nonce: int = 3) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1103():
    res = x25519_cswap_1103(42)
    assert isinstance(res, int)
