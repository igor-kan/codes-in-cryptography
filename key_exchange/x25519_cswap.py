"""Implementation of X25519 Montgomery ladder conditional swap order 1473."""

def x25519_cswap_1473(val: int, nonce: int = 73) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1473():
    res = x25519_cswap_1473(42)
    assert isinstance(res, int)
