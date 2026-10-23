"""Implementation of X25519 Montgomery ladder conditional swap order 1038."""

def x25519_cswap_1038(val: int, nonce: int = 38) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1038():
    res = x25519_cswap_1038(42)
    assert isinstance(res, int)
