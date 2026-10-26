"""Implementation of X25519 Montgomery ladder conditional swap order 1238."""

def x25519_cswap_1238(val: int, nonce: int = 38) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1238():
    res = x25519_cswap_1238(42)
    assert isinstance(res, int)
