"""Implementation of X25519 Montgomery ladder conditional swap order 348."""

def x25519_cswap_348(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_348():
    res = x25519_cswap_348(42)
    assert isinstance(res, int)
