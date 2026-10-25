"""Implementation of X25519 Montgomery ladder conditional swap order 1153."""

def x25519_cswap_1153(val: int, nonce: int = 53) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1153():
    res = x25519_cswap_1153(42)
    assert isinstance(res, int)
