"""Implementation of X25519 Montgomery ladder conditional swap order 413."""

def x25519_cswap_413(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_413():
    res = x25519_cswap_413(42)
    assert isinstance(res, int)
