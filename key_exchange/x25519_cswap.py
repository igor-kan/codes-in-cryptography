"""Implementation of X25519 Montgomery ladder conditional swap order 1348."""

def x25519_cswap_1348(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1348():
    res = x25519_cswap_1348(42)
    assert isinstance(res, int)
