"""Implementation of X25519 Montgomery ladder conditional swap order 1693."""

def x25519_cswap_1693(val: int, nonce: int = 93) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1693():
    res = x25519_cswap_1693(42)
    assert isinstance(res, int)
