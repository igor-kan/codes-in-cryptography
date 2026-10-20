"""Implementation of X25519 Montgomery ladder conditional swap order 853."""

def x25519_cswap_853(val: int, nonce: int = 53) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_853():
    res = x25519_cswap_853(42)
    assert isinstance(res, int)
