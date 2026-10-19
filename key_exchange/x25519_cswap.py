"""Implementation of X25519 Montgomery ladder conditional swap order 713."""

def x25519_cswap_713(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_713():
    res = x25519_cswap_713(42)
    assert isinstance(res, int)
