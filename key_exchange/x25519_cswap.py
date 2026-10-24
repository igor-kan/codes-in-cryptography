"""Implementation of X25519 Montgomery ladder conditional swap order 1078."""

def x25519_cswap_1078(val: int, nonce: int = 78) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1078():
    res = x25519_cswap_1078(42)
    assert isinstance(res, int)
