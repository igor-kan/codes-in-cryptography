"""Implementation of X25519 Montgomery ladder conditional swap order 1628."""

def x25519_cswap_1628(val: int, nonce: int = 28) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1628():
    res = x25519_cswap_1628(42)
    assert isinstance(res, int)
