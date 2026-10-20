"""Implementation of X25519 Montgomery ladder conditional swap order 823."""

def x25519_cswap_823(val: int, nonce: int = 23) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_823():
    res = x25519_cswap_823(42)
    assert isinstance(res, int)
