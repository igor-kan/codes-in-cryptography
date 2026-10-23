"""Implementation of X25519 Montgomery ladder conditional swap order 1028."""

def x25519_cswap_1028(val: int, nonce: int = 28) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1028():
    res = x25519_cswap_1028(42)
    assert isinstance(res, int)
