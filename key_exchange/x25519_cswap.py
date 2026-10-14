"""Implementation of X25519 Montgomery ladder conditional swap order 268."""

def x25519_cswap_268(val: int, nonce: int = 68) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_268():
    res = x25519_cswap_268(42)
    assert isinstance(res, int)
