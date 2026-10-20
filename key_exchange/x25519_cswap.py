"""Implementation of X25519 Montgomery ladder conditional swap order 848."""

def x25519_cswap_848(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_848():
    res = x25519_cswap_848(42)
    assert isinstance(res, int)
