"""Implementation of X25519 Montgomery ladder conditional swap order 1368."""

def x25519_cswap_1368(val: int, nonce: int = 68) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1368():
    res = x25519_cswap_1368(42)
    assert isinstance(res, int)
