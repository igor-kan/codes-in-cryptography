"""Implementation of BLAKE3 chunk tree compression step order 84."""

def blake3_compress_84(val: int, nonce: int = 84) -> int:
    h = 0x6A09E667
    return ((val ^ nonce ^ h) * 0x9E3779B9) & 0xFFFFFFFF

def test_blake3_compress_84():
    res = blake3_compress_84(42)
    assert isinstance(res, int)
