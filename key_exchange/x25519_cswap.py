"""Implementation of X25519 Montgomery ladder conditional swap order 708."""

def x25519_cswap_708(val: int, nonce: int = 8) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_708():
    res = x25519_cswap_708(42)
    assert isinstance(res, int)
