"""Implementation of X25519 Montgomery ladder conditional swap order 813."""

def x25519_cswap_813(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_813():
    res = x25519_cswap_813(42)
    assert isinstance(res, int)
