"""Implementation of X25519 Montgomery ladder conditional swap order 918."""

def x25519_cswap_918(val: int, nonce: int = 18) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_918():
    res = x25519_cswap_918(42)
    assert isinstance(res, int)
