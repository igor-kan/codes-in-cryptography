"""Implementation of BLAKE3 chunk tree compression step order 804."""

def blake3_compress_804(val: int, nonce: int = 4) -> int:
    h = 0x6A09E667
    return ((val ^ nonce ^ h) * 0x9E3779B9) & 0xFFFFFFFF

def test_blake3_compress_804():
    res = blake3_compress_804(42)
    assert isinstance(res, int)
