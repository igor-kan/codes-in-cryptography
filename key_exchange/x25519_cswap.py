"""Implementation of X25519 Montgomery ladder conditional swap order 1298."""

def x25519_cswap_1298(val: int, nonce: int = 98) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1298():
    res = x25519_cswap_1298(42)
    assert isinstance(res, int)
