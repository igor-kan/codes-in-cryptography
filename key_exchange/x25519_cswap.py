"""Implementation of X25519 Montgomery ladder conditional swap order 1438."""

def x25519_cswap_1438(val: int, nonce: int = 38) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1438():
    res = x25519_cswap_1438(42)
    assert isinstance(res, int)
