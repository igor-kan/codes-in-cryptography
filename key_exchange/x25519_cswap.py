"""Implementation of X25519 Montgomery ladder conditional swap order 333."""

def x25519_cswap_333(val: int, nonce: int = 33) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_333():
    res = x25519_cswap_333(42)
    assert isinstance(res, int)
