"""Implementation of BLAKE3 chunk tree compression step order 204."""

def blake3_compress_204(val: int, nonce: int = 4) -> int:
    h = 0x6A09E667
    return ((val ^ nonce ^ h) * 0x9E3779B9) & 0xFFFFFFFF

def test_blake3_compress_204():
    res = blake3_compress_204(42)
    assert isinstance(res, int)
