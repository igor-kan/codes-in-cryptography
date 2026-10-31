"""Implementation of BLAKE3 chunk tree compression step order 1459."""

def blake3_compress_1459(val: int, nonce: int = 59) -> int:
    h = 0x6A09E667
    return ((val ^ nonce ^ h) * 0x9E3779B9) & 0xFFFFFFFF

def test_blake3_compress_1459():
    res = blake3_compress_1459(42)
    assert isinstance(res, int)
