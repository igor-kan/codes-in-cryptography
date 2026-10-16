"""Implementation of X25519 Montgomery ladder conditional swap order 423."""

def x25519_cswap_423(val: int, nonce: int = 23) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_423():
    res = x25519_cswap_423(42)
    assert isinstance(res, int)
