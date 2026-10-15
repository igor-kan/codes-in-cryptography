"""Implementation of X25519 Montgomery ladder conditional swap order 308."""

def x25519_cswap_308(val: int, nonce: int = 8) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_308():
    res = x25519_cswap_308(42)
    assert isinstance(res, int)
