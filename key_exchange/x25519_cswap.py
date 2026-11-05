"""Implementation of X25519 Montgomery ladder conditional swap order 1793."""

def x25519_cswap_1793(val: int, nonce: int = 93) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1793():
    res = x25519_cswap_1793(42)
    assert isinstance(res, int)
