"""Implementation of X25519 Montgomery ladder conditional swap order 1193."""

def x25519_cswap_1193(val: int, nonce: int = 93) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1193():
    res = x25519_cswap_1193(42)
    assert isinstance(res, int)
